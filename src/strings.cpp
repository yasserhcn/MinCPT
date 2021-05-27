#include "strings.hpp"

int getCharIndex(std::string text, char character, uint16_t occurence)
{
    uint16_t stringLength = text.length();
    bool found = false;
    uint16_t timesFound = 0;
    
    for (uint16_t i = 0; i < text.length(); i++)
    {
        if(text[i] == character){
            if(timesFound == occurence){
                return i;
            }
            timesFound++;
        }
    }

    return -1;
}

int getOccurences(std::string text, char character){
    
    int occ = 0;
    for (int i = 0; i < text.length(); i++)
    {
        // branchless way of checking
        occ += (text[i] == character);
    }

    return occ;
    
}

void removeLine(std::string *text, uint16_t removeIndex)
{
    int nwlnIndex = -1;
    for (uint16_t i = removeIndex; i < text->length(); i++)
    {
        if((*text)[i] == '\n'){
            nwlnIndex = i;
            break;
        }
    }

    if(nwlnIndex > 0){
        text->erase(removeIndex, nwlnIndex - removeIndex + 1);
    }
    
}