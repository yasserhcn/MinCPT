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

/*int getVectorIndex(std::vector<data> *data, uint16_t value, uint16_t occurence = 0)
{

}*/