#include <iostream>
#include <string>

#include <logging.hpp>

void logText(const char *logType, const char *text)
{
    //TODO: adding text shouldn't remove prvious text
    std::string log = "";
    std::ifstream input("Log.txt");
    if(input){
        std::string line = "";
        while (std::getline(input, line)){
            log += line + '\n';
        }
        
    }
    std::ofstream logText("Log.txt");
    logText << log << logType << text;
    logText.close();
}

void printLogs()
{
    std::ifstream logs("Log.txt");
    std::string line;
    while (std::getline(logs, line))
    {
        std::cout<<line<<std::endl;
    }
    
}

void eraseLogText()
{
    std::ofstream file("Log.txt");
    file << "";
}