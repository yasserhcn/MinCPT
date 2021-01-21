## general overview
the txt file containing the ~~stuff~~ can be used in the command line arguments or it defaults to `build.txt`

the first arguments aren't case sensitive, so *LANGUAGE* is the same as *language*<br>
on the other hand the text after the argument is case sensitive if the inputted text is a path or a name

## choosing the language and version :
- choosing the language :<br>
    to choose the language between C++ and C you need to use the **language** argument with the language name<br>
    ``` language : CPP ```<br>
    for C++ <br>
    ``` language : C ```<br>
    for C

- choosing the version :<br>
    to choose the language version you need to specify the language name plus the 2 number version with the **version** argument<br>
    for example :<br>
    when using c++17 we write :<br>
    ``` version : CPP17 ```<br>
    for the case of C99 we write :<br>
    ``` version : C99 ```<br>