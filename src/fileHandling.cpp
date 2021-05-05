#include "fileHandling.hpp"
#include "strings.hpp"
#include "logging.hpp"

void getTextFromFile(std::string fileName, std::string *text)
{
    std::ifstream file;
    file.open(fileName, std::ios_base::in);

    eraseLogText();
    if(!file){
        logText("ERROR! : ", "FILE CANNOT BE OPENED");
        std::cerr<<"can't open file : "<<fileName<<std::endl;
        return;
    }
    logText("sucessful : ", "file opened successfuly");
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
    bool quote = false;
    uint16_t nlnoccurence = 0;
    uint16_t spcoccurence = 0;
    uint16_t length = text->length();
    
    int index;
    for (uint16_t i = 0; i < length; i++)
    {
        if ((*text)[i] == '"'){
            text->erase(i, 1);
            length--;
            i--;
            if(quote){
                quote = false;
            }else{
                quote = true;
            }

        }
        // find unecessary endline characters and remove them
        index = getCharIndex(*text, '\n', nlnoccurence);
        checkNext:
        if( (*text)[index + 1] == '\n'){
            text->erase(index + 1, 1);
            length--;
            i--;
            goto checkNext;
        }
        nlnoccurence++;

        if(!quote){
            if((*text)[i] == ' '){
                text->erase(i, 1);
                length--;
                i--;
            }
        }else if((*text)[i] == ' '){
            spcoccurence++;
        }
    }

}
