#pragma once

#include <fstream>
#include <iostream> // debugging
#include <string>

// opens the file from the arguments and returns the text
void getTextFromFile(std::string fileName, std::string *text);

// gets a pointer to the text and parses it
// removes endlines
void parseText(const char *text);