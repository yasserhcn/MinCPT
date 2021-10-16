#pragma once
#include <string>
#include <iostream>
#include <strings.hpp>

#define SHOW_DEBUG 1
#define DEBUG_LOG(a) if (SHOW_DEBUG == 1){ std::cout<<a<<std::endl; }

int getProjectOcc(std::string text, int occurence);

int getNumProjects(std::string text);

//TODO : function that returns the text in beteen the proj stuff
std::string getProjectText(std::string text, int num);