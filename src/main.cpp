#include <iostream>
#include <string>
#include "fileHandling.hpp"

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

    std::cout << text << std::endl;
    
    return 0;
}