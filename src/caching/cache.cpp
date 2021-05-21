#include "cache.hpp"

void convertData(uint16_t *data, std::string *name, bool direc){
    
    if(direc){
        // int to string conversion
        /*switch (*data)
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

        case EXTRA_ARGUMENTS:
            *name = "ext";
            break;
        
        case INCLUDE_ARGUMENT:
            *name = "incl";
            break;

        case VERSION_ARGUMENT:
            *name = "ver";
            break;

        default:
            break;
        }*/



    }else{
        // string to int conversion

    }

}

void makeCache(std::vector<data> *dataIn){

    std::ofstream cacheFile("CPTBuild.bld");

    std::string text = "";
    for (int i = 0; i < dataIn->size(); i++)
    {
        text += std::to_string((*dataIn)[i].type);
        text += ':';
        text += std::to_string((*dataIn)[i].value);
        text += '\n';
    }


    cacheFile<<text;
}

void getCache(std::vector<data> *dataOut){

    std::ifstream cacheFile("CPTBuild.bld");

    std::string text = "";
    std::string line = "";
    while (std::getline(cacheFile, line)){
        text += line;
        text += '\n';
    }

    for (int i = 0; i < getOccurences(text, ':'); i++){

        int colonIndex = getCharIndex(text, ':', i);
        int nwlnIndex = getCharIndex(text, '\n', i);
        int previousnwlnIndex = getCharIndex(text, '\n', i == 0 ? 0 : (i - 1));
        previousnwlnIndex = i == 0 ? 0 : previousnwlnIndex;
        std::string arg = text.substr(previousnwlnIndex + 1, colonIndex - previousnwlnIndex - 1);
        // use vector to add the data
        std::string par = text.substr(colonIndex + 1, nwlnIndex - colonIndex - 1);
        // add data to vector
    }
    

}