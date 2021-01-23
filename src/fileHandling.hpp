#pragma once

#include <fstream>
#include <iostream> // debugging
#include <string>
#include <vector>

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