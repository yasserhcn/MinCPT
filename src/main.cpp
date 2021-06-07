#include <iostream>
#include <string>
#include "fileHandling.hpp"
#include "buildSystem.hpp"
#include "caching/cache.hpp"

struct commandArguments
{
    std::string fileName = "build.txt";
    std::string arguments;
    std::string path = "./";
    bool shouldBuild = false;
    bool caching = true;
    bool logging = false;
};

void showHelp()
{
    const std::string helpText = "-h : shows this menu\n"
                                 "-ffile.txt : specifies the file containing the build instructions\n"
                                 "-build : automatically builds the files specified in the build text file\n"
                                 "-cache : enables chaching for use with cptmake\n"
                                 "-loggs : enables loggs to be printed to screen\n";
    
    std::cout<<helpText;

}

void ParseArgument(commandArguments *argPtr, std::string text)
{

    std::cout << text << std::endl;

    switch (text[0])
    {
    case 'f':
        argPtr->fileName = text.substr(1);
        break;
    
    case 'b':
        argPtr->shouldBuild = (text == "build");
        break;
    
    case 'c':
        argPtr->caching = (text == "cache");
        break;
    
    case 'l':
        argPtr->logging = (text == "loggs");
        break;
    
    case 'h':
        showHelp();
        break;
    
    case 'd':
        argPtr->path = text.substr(3) + '/';
        break;

    default:
        break;
    }
}


int main(int argc, char *argv[])
{
    commandArguments arg;

    if(argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            char prefix[2] = { argv[i][0] , argv[i][1] };

            if(prefix[0] == '-'){
                std::string text = argv[i];
                text.erase(0, 1);
                
                ParseArgument(&arg, text);
            }

        }
        
    }

    std::string text;
    getTextFromFile((arg.path + arg.fileName), &text);

    parseText(&text);

    std::vector<data> fdata;
    lex(&text, &fdata);

    std::string command;
    makeCommand(fdata, &command, /*&files*/ &fdata);


    if(arg.logging){
        printLogs();
    }

    if(arg.caching){
        makeCache(&fdata);
    }

    if(arg.shouldBuild)
    {
        system(command.c_str());
    }

    std::cout << command << std::endl;
    
    return 0;
}