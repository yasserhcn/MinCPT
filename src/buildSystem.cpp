#include "buildSystem.hpp"
#include "strings.hpp"


int checkArgument(int type, std::string text,std::vector<data> *vecData, int index)
{
    std::map<std::string, uint16_t> argumentMap = {
                                                {"language", LANGUAGE_ARGUMENT},
                                                {"version", VERSION_ARGUMENT},
                                                {"file", FILE_ARGUMENT},
                                                {"include", INCLUDE_ARGUMENT},
                                                {"library", LIBRARY_FILE_ARGUMENT},
                                                {"libdir", LIBRARY_PATH_ARGUMENT},
                                                {"output", OUTPUT_ARGUMENT},
                                                {"args", EXTRA_ARGUMENTS}
                                              };
    
    // convert the text to lowercase
    for (uint16_t i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }

    // argument types
    if(type == ARGUMENT_TYPE)
    {
        auto itr = argumentMap.find(text);

        if(itr == argumentMap.end()){
            return 0;
        }

        return itr->second;

        // parameter types
    }else if(type == PARAMETER_TYPE)
    {
        bool found = false;

        switch ((*vecData)[index].arg)
        {
        case INCLUDE_ARGUMENT:
            return INCLUDE_PARAMETER;
            break;
        
        case FILE_ARGUMENT:
            return FILE_PARAMETER;
            break;
        
        case LIBRARY_FILE_ARGUMENT:
            return LIBRARY_FILE_PARAMETER;
            break;
        
        case LIBRARY_PATH_ARGUMENT:
            return LIBRARY_PATH_PARAMETER;
            break;
        
        case OUTPUT_ARGUMENT:
            return OUTPUT_PARAMETER;
            break;
        
        case EXTRA_ARGUMENTS:
            return EXTRA_ARGS_PARAMETER;
            break;
        }

        // c++ language version
        if(text.substr(0,3) == "cpp")
        {
            found = true;
            if (text.length() == 3){
                return LANGUAGE_CPP;
            }else
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
            }
        }

        // if we reach here, it means no type was found
        logText("WARNING : ", "invalid parameter type, ignoring...");
        return 0;

    }else{
        return 0;
        logText("ERROR : ", "invalid type, must be argument or parameter");
    }
    return 0;
}


void lex(std::string *text, std::vector<data> *vecData)
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
            logText("WARNING syntax error ", "line : " + i+1);
            std::cerr << "syntax error at line : " << i + 1 << std::endl;
            continue;
        }

        // characters before colons are arguments
        std::string argument = currentLine.substr(0, colonIndex);
        // check if the argument exists and put it in the input vector
            uint16_t argType = checkArgument(ARGUMENT_TYPE, argument, vecData);
            if(argType){
                vecData->push_back(data(argType, 0));
            }

        // characters after colon are the parameters
        std::string parameter = currentLine.substr(colonIndex + 1, getCharIndex(currentLine, '\n') - colonIndex - 1);
            // check if the parameter is valid and put the parameter in the input vector
            uint16_t parType = checkArgument(PARAMETER_TYPE, parameter, vecData, i);
            if(parType){
                vecData->at(i).par = parType;
                vecData->at(i).parName = parameter;
            }
    }
}

std::string getCommand(uint16_t type, std::vector<data> *vecData, int index)
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
        logText("file found : ", ((*vecData)[index].parName).c_str());
        return (*vecData)[index].parName;
        break;
    
    case INCLUDE_PARAMETER:
        logText("include path found : ", ((*vecData)[index].parName).c_str());
        return ("-I\"" + (*vecData)[index].parName + "\"");
        break;
    
    case LIBRARY_FILE_PARAMETER:
        logText("library file found : ", ((*vecData)[index].parName).c_str());
        return ("-l\"" + (*vecData)[index].parName + "\"");
        break;

    case LIBRARY_PATH_PARAMETER:
        logText("library file path found : ", ((*vecData)[index].parName).c_str());
        return ("-L\"" + (*vecData)[index].parName + "\"");
        break;
    
    case OUTPUT_PARAMETER:
        logText("output file found : ", ((*vecData)[index].parName).c_str());
        return ("-o " + (*vecData)[index].parName);
        break;
    
    case EXTRA_ARGS_PARAMETER:
        logText("extra arguments detected : ", ((*vecData)[index].parName).c_str());
        return (*vecData)[index].parName;
        break;

    default:
        logText("WARNING : ", "invalid getCommand value, ignoring...");
        return "";
        break;
    }
}

void makeCommand(std::vector<data> dataIn, std::string *command, std::vector<data> *vecData)
{
    *command = "";
    bool lang = false;
    int fileIndex = 0;
    for (uint16_t i = 1; i < dataIn.size(); i++)
    {
        // language type
        if((dataIn)[0].par == LANGUAGE_CPP && lang == false)
        {
            command->insert(0, "g++ ");
            logText("language detected successfully ", "C++");
            lang = true;
        }else if((dataIn)[0].par == LANGUAGE_C && lang == false)
        {
            command->insert(0, "gcc ");
            logText("language detected successfully", "C");
            lang = true;
        }

        // add command to the string
        *command += getCommand((dataIn)[i].par, vecData, i);
        *command += " ";
        
    }
    
}