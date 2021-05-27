#pragma once

#include <string>
#include <iostream> // debugging

// get the index of a character
int getCharIndex(std::string text, char character, uint16_t occurence = 0);

// get the amount of characters in a string
int getOccurences(std::string text, char character);

// removes a line of text from the starting index
void removeLine(std::string *text, uint16_t removeIndex);