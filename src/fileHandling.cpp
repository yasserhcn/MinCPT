#include "fileHandling.hpp"

void getTextFromFile(std::string fileName, std::string *text)
{
    std::ifstream file;
    file.open(fileName, std::ios_base::in);

    if(!file){
        std::cerr<<"can't open file : "<<fileName<<std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        *text += line;
    }
    
}

void parseText(const char *text)
{

}