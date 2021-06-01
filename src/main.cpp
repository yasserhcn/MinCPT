#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "fileHandling.hpp"
#include "buildSystem.hpp"
#include "caching/cache.hpp"

int main(int argc, char *argv[])
{
    std::string fileName = "build.txt";
    std::string arguments;
    bool shouldBuild = false;
    bool caching = true;
    bool logging = false;

    if(argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            char prefix[2] = { argv[i][0] , argv[i][1] };

            if(prefix[0] == '-'){
                std::string text = argv[i];
                text.erase(0, 2);
                switch (prefix[1])
                {
                case 'f':
                    fileName = text + ".txt";
                    break;
                
                case 'b':
                    shouldBuild = (text == "uild");
                    break;
                
                case 'c':
                    caching = (text == "ache");
                    break;
                
                case 'l':
                    logging = (text == "ogging");
                    break;
                
                default:
                    break;
                }
            }

        }
        
    }

    std::string text;
    getTextFromFile(fileName, &text);

    parseText(&text);

    std::vector<data> fdata;
    lex(&text, &fdata);

    std::string command;
    makeCommand(fdata, &command, /*&files*/ &fdata);


    if(logging){
        printLogs();
    }

    if(caching){
        makeCache(&fdata);
    }

    if(shouldBuild)
    {
        system(command.c_str());
    }

    std::cout << command << std::endl;
    
    return 0;
}