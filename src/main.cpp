#include <iostream>
#include <string>
#include <stdlib.h>
#include "fileHandling.hpp"
#include "compilers/gccCompile.cpp"

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
    lex(&text, &data);

    system("gcc main.c -o main2.exe");
    system("cls");
    //std::cout << text << std::endl;
    
    return 0;
}