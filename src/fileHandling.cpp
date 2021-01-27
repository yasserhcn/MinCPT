#include "fileHandling.hpp"
#include "strings.hpp"


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
        *text += '\n';
    }
    
}

void parseText(std::string *text)
{
    uint16_t occurences = 0;
    
    int index;
    for (uint16_t i = 0; i < text->length(); i++)
    {
        // find unecessary endline characters and remove them
        index = getCharIndex(*text, '\n', occurences);
        checkNext:
        if( (*text)[index + 1] == '\n'){
            text->erase(index + 1, 1);
            goto checkNext;
        }

        // find spaces and remove them
        space:
        index = getCharIndex(*text, ' ', occurences);
        if((*text)[index] == ' '){
            text->erase(index, 1);
            goto space;
        }

        occurences++;
    }
}
