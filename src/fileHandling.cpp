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

int checkArgument(int type, std::string text)
{
    // convert the text to lowercase
    for (uint16_t i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
    std::cout<<text<<std::endl;

    if(type == ARGUMENT_TYPE)
    {
        //if(text == "language")

    }else if(type == PARAMETER_TYPE)
    {


    }
}

void lex(std::string *text, std::vector<data> *data)
{
    int amountOfLines = 0;
    int occurence = 0;
    std::vector<uint16_t> lines;
    uint16_t index = getCharIndex(*text, '\n', occurence);
    while (index != -1 && index < text->size())
    {
        index = getCharIndex(*text, '\n', occurence);
        lines.push_back(index);
        amountOfLines++;
        occurence++;
    }
    amountOfLines--;
    lines.pop_back();
    
    // TODO: a loop that doesn't exit till you reach the end of the string
    for (uint16_t i = 0; i < amountOfLines; i++)
    {
        // TODO: get a line till you reach an endline character
        std::string currentLine = text->substr(i == 0 ? 0 : lines[i - 1] + 1, lines[i] - lines[i - 1]);
        
        // TODO: get the colon character
        int colonIndex = getCharIndex(currentLine, ':');
        if(colonIndex == -1)
        {
            std::cerr << "syntax error at line : " << i + 1 << std::endl;
            continue;
        }

        // TODO: characters before colons are arguments
        std::string argument = currentLine.substr(0, colonIndex);
            // TODO: check if the argument exists
            switch (checkArgument(ARGUMENT_TYPE, argument))
            {
            case LANGUAGE_ARGUMENT:
                std::cout<<"language argument\n";
                break;
            case VERSION_ARGUMENT:
                std::cout<<"version argument\n";
                break;
            
            default:
                std::cout<<"invalid argument\n";
                break;
            }
            // TODO: put the argument in the input vector

        // TODO: characters after colon are the parameters
        std::string parameter = currentLine.substr(colonIndex + 1, getCharIndex(currentLine, '\n') - colonIndex - 1);
            // TODO: check if the parameter is valid
            // TODO: put the parameter in the input vector
        
        std::cout<<"the argument is : " << argument<<std::endl;
        std::cout<<"the parameter is : "<<parameter<<std::endl;
    }
}