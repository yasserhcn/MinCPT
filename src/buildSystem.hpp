#pragma once

#include <string>
#include <iostream> // debugging
#include <memory>
#include <vector>


#define ARGUMENT_TYPE 10
#define PARAMETER_TYPE 20

#define LANGUAGE_ARGUMENT 30
#define VERSION_ARGUMENT 31
#define FILE_ARGUMENT 32
#define OUTPUT_ARGUMENT 33
#define EXTRA_ARGUMENTS 34

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

#define FILE_PARAMETER 160

// global variable bad, gotta find another way if it exists
struct data
{
    data(){}
    data(uint8_t typeIn, uint8_t valueIn) :type(typeIn), value(valueIn){}
    uint8_t type;
    uint8_t value;
};

// checks if the argument exists and returns the type
int checkArgument(int type, std::string text);

// lexer to return the arguments and values
void lex(std::string *text, std::vector<data> *data);

std::string getCommand(uint16_t type);

// make the command to do the syscall
void makeCommand(std::vector<data> data, std::string *command);