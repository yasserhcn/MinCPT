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

    std::vector<data> fdata;
    //std::vector<std::string> files;
    lex(&text, &fdata);

    /* output vector data for debugging
    std::cout << "vector data -----------------------------" << std::endl;
    for (int i = 0; i < fdata.size(); i++)
    {
        std::cout << "------"<<i<<"-----" << std::endl;
        std::cout << "type : "<< (int)fdata[i].type << std::endl;
        std::cout << "value : "<< (int)fdata[i].value << std::endl;
        std::cout << "name : "<< fdata[i].name << std::endl;
    }
    std::cout << "end vector data --------------------------" << std::endl;
    */

    std::string command;
    makeCommand(fdata, &command, /*&files*/ &fdata);
    
    std::cout<<command;
    if(shouldBuild)
    {
        system(command.c_str());
    }
    
    return 0;
}