#pragma once

#include <string>
#include <iostream> // debugging
#include <memory>
#include <vector>
#include <map>
#include "logging.hpp"


#define ARGUMENT_TYPE 10
#define PARAMETER_TYPE 20

#define LANGUAGE_ARGUMENT 30
#define VERSION_ARGUMENT 31
#define FILE_ARGUMENT 32
#define LIBRARY_FILE_ARGUMENT 33
#define LIBRARY_PATH_ARGUMENT 34
#define INCLUDE_ARGUMENT 35
#define OUTPUT_ARGUMENT 36
#define EXTRA_ARGUMENTS 37

#define VERSION_PARAMETER 130
#define VERSION_CPP98 131
#define VERSION_CPP03 132
#define VERSION_CPP11 133
#define VERSION_CPP14 134
#define VERSION_CPP17 135
#define VERSION_CPP20 136

#define LANGUAGE_PARAMETER 150
#define LANGUAGE_C 151
#define LANGUAGE_CPP 152
#define INCLUDE_PARAMETER 160
#define LIBRARY_FILE_PARAMETER 170
#define LIBRARY_PATH_PARAMETER 180
#define OUTPUT_PARAMETER 190
#define FILE_PARAMETER 200
#define EXTRA_ARGS_PARAMETER 210

// the data struct for the vector
struct data
{
    data(){}
    data(uint8_t typeIn, uint8_t valueIn) :arg(typeIn), par(valueIn){}
    data(uint8_t typeIn, uint8_t valueIn, std::string nameIn) :arg(typeIn), par(valueIn), parName(nameIn){}
    uint8_t arg;
    uint8_t par;
    std::string parName = "";
};

// checks if the argument exists and returns the type
int checkArgument(int type, std::string text, std::vector<data> *vecData, int index = -1);

// lexer for converting sting into data
void lex(std::string *text, std::vector<data> *dataIn, std::string path = "");

// returns the command string of the argument/parameter
std::string getCommand(uint16_t type,  std::vector<data> *vecData, int index = 0, std::string extraPath = "");

// turn the data into command string and syscall
void makeCommand(std::vector<data> dataIn, std::string *command, std::vector<data> *vecData, std::string path = "");