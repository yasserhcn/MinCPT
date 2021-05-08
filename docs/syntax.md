## general overview
the txt file containing the commands can be specified in the command line arguments else it defaults to `build.txt`

the argument isn't case sensitive, so *LANGUAGE* is the same as *language*<br>
on the other hand the parameter is case sensitive if the inputted text is a path or a name

each line needs to have **only one** argument and parameter

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

- specifying the file :<br>
    to choose the file you need to write the filename including the extension name<br>
    example:<br>
    we have a file named ` main.cpp`<br>
    so we write the following ``` file : main.cpp ```

- include directories :<br>
    to set an include directory for the compiler to search through we use the word `include` followed by the path of the include folder <br>
    example:<br>
    if we have the following path `C:\programming thing\project\include` <br>
    we'll have the following syntax : ```include : C:\programming thing\project\include```

- library directory :<br>
    to specify to directory containing the library files for the compiler to search through we use the word `libdir` followed by the path of the library folder <br>
    example:<br>
    if we have the following path ```C:\programming thing\project\library``` <br>
    we'll have the following text : ``` libdir : C:\programming thing\project\library```

- library files :<br>
    to point to the files with the library files you need to specify the `library` argument with the name of the library file<br>
    example:<br>
    library file that has the name `libcThing.a` <br>
    we'll have the following line `library : cThing` <br>
    **note** : we don't use the prefix `lib` in the library file name because gcc automatically add it when specifying the library file

- outputting :<br>
    to specify the name of the output file you need to use the `output` arguyment followed by the name of the output file<br>
    example:<br>
    exectuable with the name `executable123.exe` <br>
    we'll have the following line : `output : executable123.exe`<br

## running the built file
assuming that the built file is `CPT.exe`, you should open command prompt or the terminal and run the executable with the arguments that you want<br>
the arguments are :<br>
- `-bbuild` : builds the project right away
- `-bno-build` : doesn't build the file

**important notes**:<br>
- the program automatically builds the file if `-bno-build` or `-bbuild` isn't use

## executing
when executing the program, it will create a log file called `Log.txt` in the directory the executable is located at, this file will only work for the latest time you executed it, when running it a second time the text inside of it will be overwritten

## good practices
- it's best to specify the language first, then the files, and then after that the language version