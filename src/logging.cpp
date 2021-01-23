#include "logging.hpp"

void logText(const char *logType, const char *text)
{
    std::ofstream logText("Log.txt");
    logText << logType << " : " << text;
    logText.close();
}