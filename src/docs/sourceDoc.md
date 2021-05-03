## buildSystem
file is responsible of handling ann stuff related to reading text to making the command<br>
**functions:**
- checkArgument :<br> checks an Inputted argument as a string and places the result in a vector containing the data for it
- lex : <br> puts the data from the extracted text into a data vector
- getCommand : <br> returns command as a string from the types
- makeCommand : <br> makes the command using the data vector

## fileHandling
used for accessing files and retrieving text, also containes a parser<br>
**functions:**
- getTextFromFile : <br> extracts the text from a text file
- parseText : <br> parses the text so it's more readable to the build system functions
  
## strings
containes helpful functions for string access and manipulation<br>

## logging
responsible for having functions used for logging<br>