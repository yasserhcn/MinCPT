#include "buildSystem.hpp"
#include "strings.hpp"


int checkArgument(int type, std::string text, std::vector<std::string> *files)
{
    // convert the text to lowercase
    for (uint16_t i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }

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
        }else
        if(text == "include"){
            return INCLUDE_ARGUMENT;
        }else
        if(text == "library"){
            return LIBRARY_FILE_ARGUMENT;
        }else
        if(text == "libdir"){
            return LIBRARY_PATH_ARGUMENT;
        }

    }else if(type == PARAMETER_TYPE)
    {
        // TODO: change the function so it knows what the previous argument was
        // TODO: change the way include paths are detected (should change with the above one)
        //the parameter is a file
        // put this in its own function so different extensions are easy to manage
        // ! CHANGE THE WAY IT'S CHECKED FOR A MORE ROBUST WAY
        if(text.length() > 6){
            if(text.substr(text.length()-7, 7) == "include")
            {
                files->push_back(text);
                return INCLUDE_PARAMETER;
            }
        }
        if(text.length() > 3){
            if(text.substr(text.length()-3, 3) == "cpp" || text.substr(text.length()-1, 1) == "c")
            {
                files->push_back(text);
                return FILE_PARAMETER;
            }else if(text.substr(text.length()-2, 2) == ".a"){
                files->push_back(text);
                return LIBRARY_FILE_PARAMETER;
            }else
            if(text.substr(text.length()-3, 3) == "lib"){
                files->push_back(text);
                return LIBRARY_PATH_PARAMETER;
            }
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
    
    // a loop that doesn't exit till you reach the end of the string
    for (uint16_t i = 0; i < amountOfLines; i++)
    {
        // get a line till you reach an endline character
        std::string currentLine = text->substr(i == 0 ? 0 : lines[i - 1] + 1, lines[i] - lines[i - 1]);
        
        // get the colon character
        int colonIndex = getCharIndex(currentLine, ':');
        if(colonIndex == -1)
        {
            std::cerr << "syntax error at line : " << i + 1 << std::endl;
            continue;
        }

        // characters before colons are arguments
        std::string argument = currentLine.substr(0, colonIndex);
            // check if the argument exists and put it in the input vector
            // ! CHANGE IT SO IT WOULDN'T USE A SWITCH STATEMENT 
            // TODO: change it so "checkArgument" puts the value directly into the data vector
            switch (checkArgument(ARGUMENT_TYPE, argument, files))
            {
            case LANGUAGE_ARGUMENT:
                InputData->push_back(data(LANGUAGE_ARGUMENT, 0));
                break;
            case VERSION_ARGUMENT:
                InputData->push_back(data(VERSION_ARGUMENT, 0));
                break;
            case FILE_ARGUMENT:
                InputData->push_back(data(FILE_ARGUMENT, 0));
                break;
            case INCLUDE_ARGUMENT:
                InputData->push_back(data(INCLUDE_ARGUMENT, 0));
                break;
            case LIBRARY_FILE_ARGUMENT:
                InputData->push_back(data(LIBRARY_FILE_ARGUMENT, 0));
                break;
            case LIBRARY_PATH_ARGUMENT:
                InputData->push_back(data(LIBRARY_PATH_ARGUMENT, 0));
                break;
            
            default:
                std::cout<<"invalid argument\n";
                break;
            }

        // characters after colon are the parameters
        std::string parameter = currentLine.substr(colonIndex + 1, getCharIndex(currentLine, '\n') - colonIndex - 1);
            // check if the parameter is valid
            // put the parameter in the input vector
            // TODO: do the same with this like the previous switch statement
            switch (checkArgument(PARAMETER_TYPE, parameter, files))
            {
            case VERSION_CPP20:
                InputData->at(i).value = VERSION_CPP20;
                break;

            case VERSION_CPP17:
                InputData->at(i).value = VERSION_CPP17;
                break;

            case VERSION_CPP14:
                InputData->at(i).value = VERSION_CPP14;
                break;
            
            case VERSION_CPP11:
                InputData->at(i).value = VERSION_CPP11;
                break;
            
            case VERSION_CPP03:
                InputData->at(i).value = VERSION_CPP03;
                break;

            case VERSION_CPP98:
                InputData->at(i).value = VERSION_CPP98;
                break;
            
            case LANGUAGE_CPP:
                InputData->at(i).value = LANGUAGE_CPP;
                break;

            case FILE_PARAMETER:
                InputData->at(i).value = FILE_PARAMETER;
                break;
            
            case INCLUDE_PARAMETER:
                InputData->at(i).value = INCLUDE_PARAMETER;
                break;
            
            case LIBRARY_FILE_PARAMETER:
                InputData->at(i).value = LIBRARY_FILE_PARAMETER;
                break;
            
            case LIBRARY_PATH_PARAMETER:
                InputData->at(i).value =  LIBRARY_PATH_PARAMETER;
                break;

            default:
                std::cout<<"invalid parameter\n";
                break;
            }
    }
}

std::string getCommand(uint16_t type, std::vector<std::string> *files, int index)
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
    
    case FILE_PARAMETER:
        return (*files)[index];
        break;
    
    case INCLUDE_PARAMETER:
        return ("-I" + (*files)[index]);
        break;
    
    case LIBRARY_FILE_PARAMETER:
        return ("-l" + (*files)[index]);
        break;

    case LIBRARY_PATH_PARAMETER:
        return ("-L" + (*files)[index]);
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
    
    int fileIndex = 0;
    for (uint16_t i = 1; i < data.size(); i++)
    {
        *command += getCommand((data)[i].value, files, fileIndex);
        *command += " ";
        if((data)[i].value == FILE_PARAMETER || (data)[i].value == INCLUDE_PARAMETER || (data)[i].value == LIBRARY_FILE_PARAMETER){
            fileIndex++;
        }
    }
    
}