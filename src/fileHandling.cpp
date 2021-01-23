#include "fileHandling.hpp"
#include "strings.cpp"


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

void lex(std::string *text, std::vector<data> *data)
{
    int amountOfLines = 0;
    int occurence = 0;
    std::vector<uint16_t> lines;
    int index = getCharIndex(*text, '\n', occurence);
    while (index != -1 && index < text->size())
    {
        index = getCharIndex(*text, '\n', occurence);
        lines.push_back(index);
        amountOfLines++;
        occurence++;
    }
    amountOfLines--;
    lines.pop_back();
    std::cout<<amountOfLines<<std::endl;
    
    for (int i = 0; i < lines.size(); i++)
    {
        std::cout << "line n:" << index << "= ";
        std::cout << lines[i] << std::endl;
    }
    

    // TODO: a loop that doesn't exit till you reach the end of the string

    // TODO: get a line till you reach an endline character

    // TODO: get the colon character

    // TODO: characters before colons are arguments
        // TODO: check if the argument exists
        // TODO: put the argument in the input vector

    // TODO: characters after colon are the parameters
        // TODO: check if the parameter is valid
        // TODO: put the parameter in the input vector
}