## **this tool is not yet completed it's still in a very very early stage to be used**

# what is this ?
this is a minimalist and simple building tool for C++ and C without all the complicated stuff in more advanced building tools<br>
this build tool is made to be easy to use and easy to learn
## what compilers are supported ?
- currently the only supported compiler is gcc
  
## how to build
simply use the g++ by writing `g++ src/main.cpp src/fileHandling.cpp src/buildSystem.cpp src/strings.cpp -o build/minCPT.exe -std=c++11`

## known bugs
- names of paths or files that have spaces won't work
- having an invalid name for a parameter may cause a chain reaction