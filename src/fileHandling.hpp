#pragma once

#include <fstream>
#include <iostream> // debugging
#include <string>
#include <vector>
#include <ctype.h>

#define ARGUMENT_TYPE 10
#define PARAMETER_TYPE 20

#define LANGUAGE_ARGUMENT 30
#define VERSION_ARGUMENT 31

#define LANGUAGE_PARAMETER 130
#define VERSION_PARAMETER 131

// global variable bad, gotta find another way
struct data
{
    uint8_t type;
    uint8_t value;
};

// opens the file from the arguments and returns the text
void getTextFromFile(std::string fileName, std::string *text);

// gets a pointer to the text and parses it
void parseText(std::string *text);

// lexer to return the arguments and values
void lex(std::string *text, std::vector<data> *data);

// checks if the argument exists and returns the type
int checkArgument(int type, std::string text);