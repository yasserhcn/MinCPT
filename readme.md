## **this tool is not yet completed**

# what is this ?
this is a minimalist and simple building tool for C++ and C without all the complicated stuff in more advanced building tools<br>
this build tool is made to be easy to use and easy to learn
## what compilers are supported ?
- currently the only supported compiler is gcc
  
## how to build
### using gcc directly
to build the main file you can use g++ using :  `g++ src/main.cpp src/fileHandling.cpp src/buildSystem.cpp src/strings.cpp src/logging.cpp src/caching/cache.cpp src/projects/parseProj.cpp -std=c++11 -o build/minCPT.exe `

and to use the caching file you can use : `g++ src/caching/buildCache.cpp src/caching/cache.cpp src/buildSystem.cpp src/strings.cpp src/logging.cpp -std=c++11 -o build/cptmake.exe`

### using a shell script
this method works on windows, just run the `build.sh` file and the compiled files should be in the `build` folder

### using cmake
this is a cross platform method, go to your build folder and run `cmake 'path/to/CMakelists.txt'` and then run `make`