#pragma once
#include <string>
#include <iostream>
#include "../strings.hpp"


int getNumProjects(std::string text);

//TODO : function to get the project starting and ending thingy
std::pair<int ,int> getIndicesProject(std::string text, int occurence);

//TODO : function that returns the text in beteen the proj stuff