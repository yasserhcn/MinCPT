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
    int begin = getProjectOcc(text, num);
    int end = getProjectOcc(text, num + 1);
    if(end == -1)
    {
        end = text.length() - 1;
    }else
    {
        end -= 7;
        while (text[end] != '\n' && begin != text.length()-1)
        {
            end--;
        }
    }
    
    return text.substr(begin, end - begin + 1);

}