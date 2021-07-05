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

std::pair<int ,int> getIndicesProject(std::string text, int occurence)
{

}