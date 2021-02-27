## general overview
the txt file containing the ~~stuff~~ can be used in the command line arguments or it defaults to `build.txt`

the first text isn't case sensitive, so *LANGUAGE* is the same as *language*<br>
on the other hand the text after the argument is case sensitive if the inputted text is a path or a name

each line needs to have **only one** argument or else there will be a syntax error

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
    if we have the following path `D:\programming thing\project\include` <br>
    we'll have the following syntax : ```include : D:\programming thing\project\include```

- library files :<br>
    to point to the files with the library files you need to specify the `library` argument with the name of the library file<br>
    example:<br>
    library file that has the name `libcThing.a` <br>
    we'll have the following line `library : cThing` <br>
    **note** : we don't use the prefix `lib` because gcc automatically add it when specifying the library file but the `.a` prefix is currently necessary

## running the built file
assuming that the built file is `CPT.exe`, you should open command prompt or the terminal and run the executable with the arguments that you want<br>
the arguments are :<br>
- `--build` : builds the project right away
- `--no-build` : doesn't build the file
  
**important notes**:<br>
- you *must* specify the filename as the first argument when using other arguments
- include path *must* end with the folder `include` (temporary)
- library paths *must* end with the folder `library` (temporary)
- the program automatically builds the file if `--no-build` or `--build` isn't used
  
  (temporary) : means that they're currently required to be used but are planned to be changed

## good practices
- it's best to specify the language first, then the files, and then after that the language version
- library files are better last