#pragma once

#include <fstream>
#include <iostream> // debugging
#include <string>
#include <vector>
#include <ctype.h>

#define SHOW_DEBUG 1
#define DEBUG_LOG(a) if (SHOW_DEBUG == 1){ std::cout<<a<<std::endl; }

// opens the file from the arguments and returns the text
void getTextFromFile(std::string fileName, std::string *text);

// gets a pointer to the text and parses it
void parseText(std::string *text);