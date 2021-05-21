#pragma once

#include "../buildSystem.hpp"
#include "../strings.hpp"
#include <vector>
#include <fstream>
#include <string>

// function used to find the corresponding cache text from the data
// takes a pointer to the data int and a pointer to the string
// also takes an optional parameter for string to int or the reverse
void convertData(uint16_t *data, std::string *name, bool direc = true);

// function to convert the data vector into a file
void makeCache(std::vector<data> *dataIn);

void getCache(std::vector<data> *dataOut);
