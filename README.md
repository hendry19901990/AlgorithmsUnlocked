# Algorithms Unlocked

```Code because you like it not because you have to do it. ```

```Coding is an art. It is a passion of high order```

```To err is human, wish g++ could have understood that```.

## Get Inspired 
![alt tag](https://user-images.githubusercontent.com/25129399/38405131-f1fc44f0-398b-11e8-8568-144048484af2.png).

Library of algorithms written in pure ```C++ (14)``` & ```C```. Some are written in ```Node.js```
Web Interface is written in pure javascript and runs behind a ```Node.js``` server. 
Compile/Build the source code files using ```Cmake```, ```CLang/LLVM``` & ```Mingw64```.

First Basic C++  & Node.js Syntax & Coding Practices are discussed. 
The folder ```Source Files``` contains basic ```C++``` & ```Node.js``` tutorials for beginners.
It will give someone a feel as to how coding in ```C++``` or ```Node.js``` is. 

Build files and code for ```Windows Application (Using C++)``` & ```Node.js``` Website for problem solving and Competitive Programming will be put in soon under 
```Windows Application``` & ```Nodejs Website``` folder by ``` 24th June, 2018 ```.

### Later Additions : 

You share the solutions and guides to help solve problems from, 
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
## From Command Line (Prerequisite)
```Add g++, gcc, clang & clang++ to path env variables. While installing MinGW or Cygwin on Windows as well as on Linux.```
Add to PATH ```\bin``` directory of all of them.

### Options for ```g++```.
```-w/-W  : Compiler Warnings.```

```-O2/-O3  : Compiler Optimizations.```

```-all  : All the files generated during compilation. ```

```-march=native : Auto-Vectorization.```

## C++ General Tips : 

Use of vectors, maps, hash_maps, sets, pairs & other STL data types reduce chances of errors and result in more efficient code. 
```C++
std::vector<int> vec;

std::vector<char> myvector;

pair<string, pair<int, int> >	P;

vector< pair< double, pair<int, int> > > coordinate_system(10);

std::bitset<8> bar(std::string("10110010"));

vector<string> v{"one","two","three","four","five","six"};

std::queue<char, vector<char> > char_stack;

std::deque<int> mydeque (2, 1500);
```
Use Macros & Refernces wherever possible
```C++
#define sz(a) int((a).size())

#define pb push_back 

#define all(c) (c).begin(), (c).end()

#define present(c,x) ((c).find(x) != (c).end()) 

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)

```
When working with ```int``` or ```double``` data-types, check for overflow and byte allignment conditions. There may be amny other data types also for which overflow condition checking is a must. 


## Installations
#### Node.js Install : https://nodejs.org/en/download/
#### Cygwin Install : https://cygwin.com/install.html
#### MinGW Install : https://atom.io/
#### Visual Studio Code Install : https://code.visualstudio.com/
#### Follow this tutorial first : http://blog.johannesmp.com/2015/09/01/installing-clang-on-windows-pt2/
#### Learn & Read this : https://clang.llvm.org/get_started.html 
#### CMake : https://cmake.org/cmake-tutorial/

## Node.js
#### Running & Compiling using Node,js.
To compile & run using Node.js, the follwoing code will come handy. 
Make sure ```Node.js``` is already installed. 
Place ```run.js``` file in the directory.
The file contains this code. It starts a child process ```start``` which in-turn starts
```complie``` & ```run``` processes.

```javascript
var spawn = require('child_process').spawn;
var start = spawn('ls');
start.on('close', function(data){
  if(data === 0) {
    var compile = spawn('g++',['run.cpp','-O3','-W','-pedantic','-march=native','-o','run.exe']);
    compile.stdout.on('data', (data) => {
        console.log('status : Compiling Started : ' + data);
    });
    compile.stderr.on('data', (data) => {
        console.log(String(data));
    });
    compile.on('close', (output, jsonDate) =>  {
      console.log('Compilation done. Exited with code ' + output);
      var run = spawn('./run.exe', []);
      run.stdout.on('data', (output) => {
          console.log(String(output));
      });
      run.stderr.on('data', (output) => {
          console.log(String(output));
      });
      run.on('close', (output) => {
          console.log('Execution done. Exited with code ' + output);
      })
    })
  }
})
```

To change the command line options, make changes in the line, under ```[" "]``` part

```javascript
 var compile = spawn('g++',['run.cpp','-O3','-W','-pedantic','-march=native','-o','run.exe'])
 ```
It takes ```run.cpp``` as the input C++ file. To change the file, type the name of the file to compile. ```{name-of-file-to-compile}.cpp```.

Eg. file.cpp > ```file.cpp``` in the code below.
 
```javascript
 var compile = spawn('g++',['{name-of-file-to-compile}.cpp','-O3','-W','-pedantic','-march=native','-o','run.exe', '{other-cmdline-options}'])
 ```

Type in ```terminal``` or ```cmd``` :
```bash
Check installation.
$ node -v 
$ npm -v
$ node run.js
```

#### Covers Node.js tutorials as well. Check libjscript folder.
```bash
$ node -v
$ npm -v
$ sudo node ${Name-of-js-file.js}
```

## Maintaining Byte Alignment in C++ code 
 ```C++
 typedef double *__attribute__((aligned(64))) aligned_double;
 typedef int *__attribute__((aligned(32))) aligned_double;
 ```
## Using Builtin properly
```C++
// Compile with -O3 -march=native to see autovectorization
// assumes input is aligned on 32-byte boundary and that
// length is a multiple of 32.
int Function(int* input, int length) {
	// Alignment hints supported on GCC 4.7+ and any compiler
	// supporting the appropriate builtin (clang 3.6+).
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif
#if __GNUC__ > 4 \
    || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7) \
    || __has_builtin(__builtin_assume_aligned)
	input = static_cast<int*>(__builtin_assume_aligned(input, 32));
#endif
#if _MSC_VER
	__assume((length & 31) == 0);
#else
	if (length & 31) __builtin_unreachable();
#endif
	int sum = 0;
	for (int i = 0; i < length; ++i) {
		sum += input[i];
	}
	return sum;
}
```
## Use of ```C++ freopen() ```.

For reading and writing into files without the filestream handlers and functions. 
```C++
freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
```

#### Again : Add to PATH ```\bin``` directory of all of them.
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
Windows
> clang++ main.cpp -o main.exe
> main.exe
```
```bash 
Linux
$ clang++ -O2 main.cpp -o main.out
$ time ./main.out
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
