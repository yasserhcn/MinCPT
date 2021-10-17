## buildSystem
file is responsible of handling ann stuff related to reading text to making the command<br>
**functions:**
- *checkArgument* : checks an Inputted argument as a string and places the result in a vector containing the data for it
- *lex* : puts the data from the extracted text into a data vector
- *getCommand* : returns command as a string from the types
- *makeCommand* : makes the command using the data vector

## fileHandling
used for accessing files and retrieving text, also containes a parser<br>
**functions:**
- *getTextFromFile* : extracts the text from a text file
- *parseText* : parses the text so it's more readable to the build system functions
  
## strings
containes helpful functions for string access and manipulation<br>
**function:**
- *getcharindex* : finds the index of a character in a string, the difference between it and the standard library function is the ability the choose the occurence of the character
- *getOccurences* : gets the amounts of characters in a string

## logging
responsible for having functions used for logging<br>
**function:**
- *logText* : adds text in a log file called `log.txt` 
- *eraseLogText* : erases text from the log file

## caching
responsible for creating and reding cache files generated from the data vector file
**functions:**
- *convertData* : not currently used, supposed to convert data from ints to strings or the other way around
- *makeCache* : creates the cache file and writes data to it from the data vector
- *getCache* : gets cache from the cache file and puts it in the data vector
  
## projects
responsible for preparsing the text files and separating them into multiple projects
**functions:**
- *getProjectOcc* : returns the index of the specified project occurence
- *getNumProjects* : returns the amount of projects in the text
- *getProjectText* : returns the text of a project from full text and the occurence