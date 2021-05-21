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
        text += (*dataIn)[i].type;
        text += ':';
        text += (*dataIn)[i].value;
        text += '\n';
    }

    cacheFile<<text;

}

void getCache(std::vector<data> *dataOut){

    std::ifstream cacheFile("CPTBuild.bld");

    std::string text = "";
    

}