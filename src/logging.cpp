#include <iostream>
#include <string>

#include "logging.hpp"

void logText(const char *logType, const char *text)
{
    //TODO: adding text shouldn't remove prvious text
    std::string log = "";
    std::ifstream input("Log.txt");
    if(input){
        std::string line = "";
        while (std::getline(input, line)){
            log += line;
        }
        
    }
    std::ofstream logText("Log.txt");
    std::cout << logType<<text << std::endl;
    logText << log << "\n" << logType << text  << std::endl;
    logText.close();
}

void eraseLogText()
{
    std::ofstream file("Log.txt");
    file << "";
}