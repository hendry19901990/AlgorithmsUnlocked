# Algorithms Unlocked

Library of algorithms written in pure ```C++ (14)``` & ```C```. Some are written in ```Node.js```
Web Interface is written in pure javascript and runs behind a ```Node.js``` server. 
Compile/Build the source code files using ```Cmake```, ```CLang/LLVM``` & ```Mingw64```.

First Basic C++  & Node.js Syntax & Coding Practices are discussed. 
The folder ```Source Files``` contains basic ```C++``` & ```Node.js``` tutorials for beginners.
It will give someone a feel as to how coding in ```C++``` or ```Node.js``` is. 

Build files and code for ```Windows Universal App (Using C++)``` & ```Node.js``` Website for problem solving and Competitive Programming will be put in soon under 
```Windows Application``` & ```Nodejs Website``` folder by ``` 24th June, 2018 ```.

### Later Additions : 

```bash 
HackerRank Problems
Hackerearth Problems
Project Euler Problems
Google Code Jam Problems
Codeforces Problems
CodeChef Problems
TopCoder Problems
IOI Problems
COCI Problems
```

## What it will cover : 

An algorithms repository. Basics of ```C++ for programming```. Stable Sorting Algorithms. Inversion Counting. AVL Trees, Red-Black Trees, 2-3-4 Trees, B-Trees, Path Commpression, 
Huffman Encoding, Disjoint Sets, Greedy Knapsack & Job Sequencing Algorithms. Graph Traversal. Dynamic Programming. 0/1 Knapsack. Bellman-Ford Algorithm, Floyd-Warshall Algorithm.
The algorithms will be added in ```Algorithms ``` Folder by ``` 25th July, 2018 ```.

## Node.js
#### Covers Node.js tutorials as well. Check libjscript folder.
```bash
$ node -v
$ npm -v
$ sudo node ${Name-of-js-file.js}
```
## Installations
#### Follow this tutorial first : http://blog.johannesmp.com/2015/09/01/installing-clang-on-windows-pt2/
#### Learn & Read this : https://clang.llvm.org/get_started.html 
#### CMake : https://cmake.org/cmake-tutorial/

Add to PATH ```\bin``` directory of all of them.
## CMake Build

```bash
$ cmake CMakeList.txt 
```
## Using CMake
```bash
$ cmake CMakeLists.txt
$ make
$ ./main 
```
## Compliling *.cpp

Assuming Clang & Mingw64 are already installed and working properly.

```bash
$ clang++ main.cpp -o main.exe
$ main.exe
```
## Generating Intermediate Represenation using LLVM Clang

```cmd
$ clang++ main.cpp -S -emit-llvm main.bc
$ clang++ main.cpp -S -emit-llvm -O3 main.bc
```
## Generating Assembly Language mnemonics

```cmd
$ clang++ main.cpp -S -O3 -o main.asm
OR
$ gcc -g -c main.cpp -o main.o
$ objdump -d -M intel main.o
OR
$ objdump -D -mcpu=<cpu-name> main.o
```
