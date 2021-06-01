#include <iostream>
#include <vector>
#include "cache.hpp"
#include "../buildSystem.hpp"

int main(int argc, char *argv[])
{
    std::vector<data> dataVec;
    getCache(&dataVec);

    std::string command;
    makeCommand(dataVec, &command, &dataVec);

    std::cout<<command<<std::endl;

    system(command.c_str());

}