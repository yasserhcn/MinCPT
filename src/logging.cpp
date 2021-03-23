#include <iostream>

#include "logging.hpp"

void logText(const char *logType, const char *text)
{
    //TODO: adding text shouldn't remove prvious text
    std::ofstream logText("Log.txt");
    std::cout << logType<<text << std::endl;
    logText << logType << text << std::endl;
    logText.close();
}