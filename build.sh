mkdir build

echo "building minCPT file..."
g++ src/main.cpp src/fileHandling.cpp src/buildSystem.cpp src/strings.cpp src/logging.cpp -o build/minCPT.exe src/caching/cache.cpp -std=c++11 -I"./src/include"
echo "done building"

echo "building cptmake file..."
g++ src/caching/buildCache.cpp src/caching/cache.cpp src/buildSystem.cpp src/strings.cpp src/logging.cpp -std=c++11 -o build/cptmake.exe -I"./src/include"
echo "done building"