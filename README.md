# AlgoGit

Library of non-conventional algorithms written in pure C++ (14) & C.
Web Interface is written in pure javascript and runs behind a Node.js server. 
Compile the source code files using Cmake, CLang/LLVM & Mingw64.
First Basic C++ Syntax & Coding Practices are discussed. 

## What it covers : 

An algorithms repository. Basics of C++ for programming. Stable Sorting Algorithms. Inversion Counting. AVL Trees, Red-Black Trees, 2-3-4 Trees, B-Trees, Path Commpression, Huffman Encoding, Disjoint Sets, Greedy Knapsack & Job Sequencing Algorithms. Graph Traversal. Dynamic Programming. 0/1 Knapsack. Bellman-Ford Algorithm, Floyd-Warshall Algorithm.

## Node.js
#### Covers Node.js tutorials as well. Check libjscript folder.
```
node -v
npm -v
sudo node ${Name-of-js-file.js}
```

# Algorithms Covered : 

```bash
1. Sorting Algorithms
    MergeSort
    QuickSort
    InsertionSort
    BubbleSort
```    


# Installations
#### Follow this tutorial first : http://blog.johannesmp.com/2015/09/01/installing-clang-on-windows-pt2/
#### Learn & Read this : https://clang.llvm.org/get_started.html 
#### CMake : https://cmake.org/cmake-tutorial/

Add to PATH ```\bin``` directory of all of them.
# CMake Build

```
> cmake CMakeList.txt 
```
# Using CMake
```
> cmake CMakeLists.txt
> make
> ./main 
```
# Compliling *.cpp

```
/* Assuming Clang & Mingw64 are already installed and working properly */ 
> clang++ main.cpp -o main.exe
> main.exe
> /* Output as per source code */
```
# Generating Intermediate Represenation using LLVM Clang

```
> clang++ main.cpp -S -emit-llvm main.bc
> clang++ main.cpp -S -emit-llvm -O3 main.bc
```
# Generating Assembly Language mnemonics

```
> clang++ main.cpp -S -O3 -o main.asm
OR
> gcc -g -c main.cpp -o main.o
> objdump -d -M intel main.o
OR
> objdump -D -mcpu=<cpu-name> main.o
```
