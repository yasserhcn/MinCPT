#include <iostream>
#include <string>
#include <stdlib.h>
#include "fileHandling.hpp"
#include "buildSystem.hpp"

int main(int argc, char *argv[])
{
    std::string fileName;
    std::string arguments;
    bool shouldBuild = true;

    if(argc >= 2)
    {
        fileName = argv[1];
        
        for (int i = 2; i < argc; i++)
        {
            if(argv[i] == "--build")
            {
                shouldBuild = true;
            }else if(argv[i] == "--no-build")
            {
                shouldBuild = false;
            }
        }
        
    }else
    {
        fileName = "build.txt";
    }

    std::string text;
    getTextFromFile(fileName, &text);
    parseText(&text);

    std::vector<data> data;
    std::vector<std::string> files;
    lex(&text, &data, &files);

    std::string command;
    makeCommand(data, &command, &files);
    std::cout<<command;

    if(shouldBuild)
    {
        system(command.c_str());
    }
    
    return 0;
}