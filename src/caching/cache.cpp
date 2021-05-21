#include "cache.hpp"

void convertData(uint16_t *data, std::string *name, bool direc = true){
    
    if(direc){
        // int to string conversion
        switch (*data)
        {
            // *arguments*
        case LANGUAGE_ARGUMENT:
            *name = "lang";
            break;
        
        case FILE_ARGUMENT:
            *name = "file";
            break;
        
        case OUTPUT_ARGUMENT:
            *name = "arg";
            break;
        
        default:
            break;
        }

    }else{
        // string to int conversion

    }

}

void makeCache(std::vector<data> *dataIn){

    std::ofstream cacheFile("CPTBuild.txt");

    std::string text = "";
    for (int i = 0; i < dataIn->size(); i++)
    {
        text += getCommand((*dataIn)[i].type, dataIn);
        text += ':';
        text += getCommand((*dataIn)[i].value, dataIn);
        text += '\n';
    }

    std::cout<<text;

}
