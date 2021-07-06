#include "parseProj.hpp"

int getNumProjects(std::string text)
{
    int lines = getOccurences(text, '\n');
    int beginning = 0, projects = 0;

    for (int i = 0; i < lines; i++)
    {
        std::string line = text.substr(beginning, getCharIndex(text, '\n', i));
        beginning = getCharIndex(text, '\n', i) + 1;

        if(line.substr(0, 7) == "PROJECT")
        {
            projects++;
        }
    }
    return projects;
}

int getProjectOcc(std::string text, int occurence)
{
    int occ = 0;

    int lines = getOccurences(text, '\n');
    int beginning = 0;

    for (int i = 0; i < lines; i++)
    {
        std::string line = text.substr(beginning, getCharIndex(text, '\n', i));
        beginning = getCharIndex(text, '\n', i) + 1;

        if(line.substr(0, 7) == "PROJECT")
        {
            if(occ == occurence){
                return getCharIndex(text, '\n', i);
            }
            occ++;
        }
    }
    return -1;

}

std::string getProjectText(std::string text, int num)
{
    
}