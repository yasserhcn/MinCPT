#include <iostream>
#include <string>
#include <stdlib.h>
#include "fileHandling.hpp"
#include "buildSystem.hpp"

int main(int argc, char *argv[])
{
    std::string fileName;

    if(argc == 2)
    {
        fileName = argv[1];
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
    
    return 0;
}