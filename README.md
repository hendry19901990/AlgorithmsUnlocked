# AlgoGit
Library of non-conventional algorithms written in pure C++ (14) & C.

Web Interface is written in pure javascript and runs behind a Node.js server. 

Compile the source code files using Cmake, CLang/LLVM & Mingw64.

#Installations
####Follow this tutorial first : http://blog.johannesmp.com/2015/09/01/installing-clang-on-windows-pt2/
####Learn & Read this : https://clang.llvm.org/get_started.html 
####CMake : https://cmake.org/cmake-tutorial/

Add to PATH ```\bin``` directory of all of them.

#Cmake Build
```bash
> cmake CMakeList.txt 
```

#Compliling main.cpp
```bash
/* Assuming Clang & Mingw64 are already installed and working properly */ 
> clang++ main.cpp -o main.exe
> main.exe
> /* Output as per source code */
```

#Generating Intermediate Represenation using LLVM Clang
```bash 
> clang++ main.cpp -S -emit-llvm main.bc
> clang++ main.cpp -S -emit-llvm -O3 main.bc
```

#Generating Assembly Language mnemonics
```bash
> clang++ main.cpp -S -O3 -o main.asm
OR
> gcc -g -c main.cpp -o main.o
> objdump -d -M intel main.o
> objdump -D -mcpu=<cpu-name> main.o
