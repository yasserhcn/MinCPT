#include "buildSystem.hpp"
#include "strings.hpp"


int checkArgument(int type, std::string text, std::vector<std::string> *files)
{
    // convert the text to lowercase
    for (uint16_t i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
    //std::cout<<text<<std::endl;

    if(type == ARGUMENT_TYPE)
    {
        if(text == "language"){
            return LANGUAGE_ARGUMENT;
        }else
        if(text == "version"){
            return VERSION_ARGUMENT;
        }else
        if(text == "file"){
            return FILE_ARGUMENT;
        }

    }else if(type == PARAMETER_TYPE)
    {
        //the parameter is a file
        // TODO: put this in its own function so different extensions are easy to manage
        std::cout << "checking filetype" << std::endl;
        if(text.length() > 3)
            if(text.substr(text.length()-3, 3) == "cpp" || text.substr(text.length()-1, 1) == "c")
            {
                files->push_back(text);
                std::cout<<"the text is : "<<text<<std::endl;
                std::cout << "cpp -> "<<text.substr(text.size()-3, 3)<<"c -> "<< text.substr(text.size()-1, 1)<< std::endl;
                return FILE_PARAMETER;
            }
        // the parameter is a language thingy
        if(text.substr(0,3) == "cpp")
        {
            if(text.substr(3, 2) == "20"){
                return VERSION_CPP20;
            }else
            if(text.substr(3, 2) == "17"){
                return VERSION_CPP17;
            }else
            if(text.substr(3, 2) == "14"){
                return VERSION_CPP14;
            }else
            if(text.substr(3, 2) == "11"){
                return VERSION_CPP11;
            }else
            if(text.substr(3, 2) == "03"){
                return VERSION_CPP03;
            }else
            if(text.substr(3, 2) == "98"){
                return VERSION_CPP98;
            }else if (text.length() == 3){
                return LANGUAGE_CPP;
            }
        }

    }
}


void lex(std::string *text, std::vector<data> *InputData, std::vector<std::string> *files)
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
            // TODO: check if the argument exists and put it in the input vector
            // ! CHANGE IT SO IT WOULDN'T USE A SWITCH STATEMENT 
            switch (checkArgument(ARGUMENT_TYPE, argument, files))
            {
            case LANGUAGE_ARGUMENT:
                std::cout<<"language argument\n";
                InputData->push_back(data(LANGUAGE_ARGUMENT, 0));
                break;
            case VERSION_ARGUMENT:
                std::cout<<"version argument\n";
                InputData->push_back(data(VERSION_ARGUMENT, 0));
                break;
            case FILE_ARGUMENT:
                std::cout<<"file argument\n";
                InputData->push_back(data(FILE_ARGUMENT, 0));
                break;
            
            default:
                std::cout<<"invalid argument\n";
                break;
            }

        // TODO: characters after colon are the parameters
        std::string parameter = currentLine.substr(colonIndex + 1, getCharIndex(currentLine, '\n') - colonIndex - 1);
            // TODO: check if the parameter is valid
            // TODO: put the parameter in the input vector
            switch (checkArgument(PARAMETER_TYPE, parameter, files))
            {
            case VERSION_CPP20:
                std::cout<<"cpp20\n";
                InputData->at(i).value = VERSION_CPP20;
                break;

            case VERSION_CPP17:
                std::cout<<"cpp17\n";
                InputData->at(i).value = VERSION_CPP20;
                break;
            
            case LANGUAGE_CPP:
                std::cout<<"c++ language\n";
                InputData->at(i).value = LANGUAGE_CPP;
                break;

            case FILE_PARAMETER:
                std::cout<<"file thingy\n";
                InputData->at(i).value = FILE_PARAMETER;
                break;

            default:
                std::cout<<"invalid parameter\n";
                break;
            }
        
        std::cout<<"the argument is : " << (int)(*InputData)[i].type<<std::endl;
        std::cout<<"the parameter is : "<< (int)(*InputData)[i].value<<std::endl;
    }
}

std::string getCommand(uint16_t type)
{
    switch (type)
    {
        // versions
    case VERSION_CPP20:
        return "-std=c++20";
        break;
    case VERSION_CPP17:
        return "-std=c++17";
        break;
    case VERSION_CPP14:
        return "-std=c++14";
        break;
    case VERSION_CPP11:
        return "-std=c++11";
        break;
    case VERSION_CPP03:
        return "-std=c++03";
        break;
    case VERSION_CPP98:
        return "-std=c++98";
        break;
    

    
    default:
        break;
    }
}

void makeCommand(std::vector<data> data, std::string *command, std::vector<std::string> *files)
{
    *command = "";
    if((data)[0].value == LANGUAGE_CPP)
    {
        *command += "g++ ";
    }else if((data)[0].value == LANGUAGE_C)
    {
        *command += "gcc";
    }
    
    for (uint16_t i = 1; i < data.size(); i++)
    {
        *command += getCommand((data)[i].value);
    }
    
}