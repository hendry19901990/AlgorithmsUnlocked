# Algorithms Unlocked

### ```Code because you like to not because you have to. ```

### ```Coding is an art. It is a passion of high order.```


Library of algorithms written in pure ```C++ (14)``` & ```C```. Some are written in ```Node.js```
Web Interface is written in pure javascript and runs behind a ```Node.js``` server. 
Compile/Build the source code files using ```Cmake```, ```CLang/LLVM``` & ```Mingw64```.

First Basic C++  & Node.js Syntax & Coding Practices are discussed. 
The folder ```Source Files``` contains basic ```C++``` & ```Node.js``` tutorials for beginners.
It will give someone a feel as to how coding in ```C++``` or ```Node.js``` is. 

Build files and code for ```Windows Application (Using C++)``` & ```Node.js``` Website for problem solving and Competitive Programming will be put in soon under 
```Windows Application``` & ```Nodejs Website``` folder.
### Sample Question :
Consider the graph shown on the figure. The function ```random()``` generates a random interger between ```0``` and ```range```. 
Write code in language of your choice to perform the following as shown below. 

#### Note : Please ask all necessary questions to the interviwer, incase it comes up in an interview.

![alt-tag](https://raw.githubusercontent.com/SpawnTree/AlgorithmsUnlocked/master/graph.jpg)

C++ Code to perform the following tasks : 
```C++
template<typename T>
class Comp_fn
{
	bool reverse;
public:
	Comp_fn(const bool& t = false)
	{
		reverse = t;
	}
	bool operator() (const T& _lhs, const T& _rhs)
	{
		if (reverse) return (_lhs > _rhs);
		else return (_lhs < _rhs);
	}
};
template<typename T>
struct Edge
{
	T vertex1;
	T vertex2;
	long long weight;
	Edge(T a, T b, long long f) : vertex1(a), vertex2(b), weight(f) {}
	Edge(T a, T b) : vertex1(a), vertex2(b), weight(0) {}
	void setWeight(const long long& w) { this->weight = w; }
};
template<typename T>
struct Graph
{
	vector<T> vertices;
	vector<Edge<T> > edges;
	vector< pair<T, Edge<T> > > FindAdjecent(T u)
	{
		vector< pair<T, Edge<T> > > graph;
		for(Edge<T> e : edges)
		{
			if(e.vertex1 == u){
				graph.push_back( make_pair(e.vertex2, e));
			} else if (e.vertex2 == u){
				graph.push_back( make_pair(e.vertex1, e));
			}
		}
		return graph;
	} 
};
	int range = 150;
	std::vector<int> A;
	std::random_device seed_device;
	std::default_random_engine generator(seed_device());
	std::uniform_int_distribution<int> random_attr(0, range);
	auto random = std::bind(random_attr, generator); 
	std::priority_queue<char, std::vector<char>, Comp_fn<char> > dijkstra_graph_queue;
	Graph<char> g;
	char t[] = {'a','b','c','d','e','f','g','h','i'};
	g.vertices = vector<char>(t, t + sizeof(t)/sizeof(t[0]));
	g.edges.emplace_back(Edge<char>('a','b', random()));
	g.edges.emplace_back(Edge<char>('b','g', 54));
	g.edges.emplace_back(Edge<char>('a','g', random()));
	g.edges.emplace_back(Edge<char>('g','f', 72));
	g.edges.emplace_back(Edge<char>('f','d', 15));
	g.edges.emplace_back(Edge<char>('b','d', random()));
	g.edges.emplace_back(Edge<char>('f','i',  6));
	g.edges.emplace_back(Edge<char>('d','i', 48));
	g.edges.emplace_back(Edge<char>('d','h',  3));
	g.edges.emplace_back(Edge<char>('h','i', random()));
	g.edges.emplace_back(Edge<char>('d','e', -2));
	g.edges.emplace_back(Edge<char>('e','c', random()));
	g.edges.emplace_back(Edge<char>('a','c', random()));
	g.edges.emplace_back(Edge<char>('c','d', 32));
	g.edges.emplace_back(Edge<char>('b','f', 46));
	g.edges.emplace_back(Edge<char>('b','e', -random()));
	map<char, Edge<char> > VisitedMap;
	set<char> VisitedSet;
	stack<char> visit_in_prog_stack;
	queue<char> visit_in_prog_queue;
	cout << "Raw Graph is :  " << endl << endl;
	for(const auto& vertex : g.vertices)
	{
		cout << "Vertex : " << vertex << endl;
		auto res = g.FindAdjecent(vertex);
		for(const auto& item : res){
			cout << "Adjecent vertices : " << item.first  << " Edge weight : " << item.second.weight << endl;
		}
	}
	auto a = g.vertices[6];
	visit_in_prog_queue.push(a);
	VisitedSet.emplace(visit_in_prog_queue.front());
	cout << endl << "1. Breadth First Search : " << endl;
	while(!visit_in_prog_queue.empty())
	{
		cout << endl;
		cout << "Visited vertex : " << visit_in_prog_queue.front();
		auto next_vert = g.FindAdjecent(visit_in_prog_queue.front());
		visit_in_prog_queue.pop();
		for(const auto& item : next_vert)
		{
			auto it = VisitedSet.find(item.first);
			if(it == VisitedSet.end())
			{
				VisitedSet.emplace(item.first);
				visit_in_prog_queue.push(item.first);
				cout << "  Pushed vertex : " << visit_in_prog_queue.front();
			}
		}
	}
	a = g.vertices[0];
	VisitedSet.clear();
	visit_in_prog_stack.push(a);
	VisitedSet.emplace(visit_in_prog_stack.top());
	cout << endl << endl << "2. Depth First Search : " << endl;
	while(!visit_in_prog_stack.empty())
	{
		cout << endl;
		cout << "Visited vertex : " << visit_in_prog_stack.top();
		auto next_vert = g.FindAdjecent(visit_in_prog_stack.top());
		visit_in_prog_stack.pop();
		for(const auto& item : next_vert)
		{
			VisitedMap.emplace(item);
			auto it = VisitedSet.find(item.first);
			if(it == VisitedSet.end())
			{
				VisitedSet.emplace(item.first);
				visit_in_prog_stack.push(item.first);
				cout << "  Pushed vertex : " << visit_in_prog_stack.top();
			}
		}
	}
	cout << endl << endl << "Map is : " << endl << endl;
	for(const auto& y : VisitedMap){
			cout << "Adjecent vertices : " << y.first  << " Edge weight : " << y.second.weight << endl;
	}
	cout << endl;
```

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
The algorithms will be added in ```Algorithms ``` folder.
## From Command Line (Prerequisite)
```Add g++, gcc, clang & clang++ to path env variables. While installing MinGW or Cygwin on Windows as well as on Linux.```
Add to PATH ```\bin``` directory of all of them.

### Options for ```g++```.
```-w/-W  : Compiler Warnings.```

```-O2/-O3  : Compiler Optimizations.```

```-all  : All the files generated during compilation. ```

```-march=native : Auto-Vectorization.```

## C++ General Tips : 

Use of vectors, maps, hash_maps, sets, pairs & other STL data types to reduce chances of errors and results in more efficient code. 
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
Use Macros & References wherever possible
```C++
#define sz(a) int((a).size())

#define pb push_back 

#define all(c) (c).begin(), (c).end()

#define present(c,x) ((c).find(x) != (c).end()) 

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)

#define print(vec) for(const auto& i : vec) cout << i << endl;

#define input(ss, inputbuffer) while(cin.good()) { getline(cin, inputbuffer); ss << inputbuffer << endl; }

```
When working with ```int``` or ```double``` data-types, check for overflow and byte allignment conditions. 
There may be amny other data types also for which overflow condition checking is a must. 

Use hashing to check for changes and tracking the same. 
Below is a snippet to hash and print/store the hash, a SHA-256 of the input.

```C++
std::string once_sha256(const std::string &type_string) {
	SHA256_CTX ptx;
	sha256_init(&ptx);
	sha256_update(&ptx, (const BYTE *)type_string.c_str(), type_string.size());
	sha256_final(&ptx, this->digest);
	std::stringstream stream;
	stream << "0x";
	for (const auto& c : this->digest)
		stream << std::hex << std::setw(2) << std::setfill('0') << (unsigned)c;
	return stream.str();
}
```
See ```Misc Codes``` folder for more uses.  
## More References :
#### STLs  &  Data Structures
https://www.topcoder.com/community/data-science/data-science-tutorials/power-up-c-with-the-standard-template-library-part-1/


https://www.topcoder.com/community/data-science/data-science-tutorials/power-up-c-with-the-standard-template-library-part-2/

http://codeforces.com/blog/entry/13529

http://codeforces.com/blog/entry/11080

https://opensource.apple.com/source/llvmgcc42/llvmgcc42-2336.9/libstdc++-v3/testsuite/ext/pb_ds/example/trie_prefix_search.cc



#### General Refs : 
https://www.topcoder.com/community/data-science/data-science-tutorials/

https://google.github.io/styleguide/cppguide.html

https://developers.google.com/edu/c++/cpp-in-depth

https://developers.google.com/edu/c++/




## Installations
#### Node.js Install : 
https://nodejs.org/en/download/
#### Cygwin Install : 
https://cygwin.com/install.html
#### MinGW Install : 
https://atom.io/
#### Visual Studio Code Install : 
https://code.visualstudio.com/
#### Visual Studio : 
https://www.visualstudio.com/vs/getting-started/
#### Git on Windows : 
https://git-scm.com/
#### Far Manager : 
https://www.farmanager.com/
#### Follow this tutorial first : 
http://blog.johannesmp.com/2015/09/01/installing-clang-on-windows-pt2/
#### Learn & Read this : 
https://clang.llvm.org/get_started.html 
#### CMake : 
https://cmake.org/cmake-tutorial/

## Setup 

Use your favourite text editor ```sublime text``` or ```Atom``` and use with command line ```see in blue```. 

![alt-tag](https://user-images.githubusercontent.com/25129399/38405232-8868896c-398c-11e8-959d-de79a279eb25.png)

Use ```Visual Studio``` for git commiting & ```git push```. The experience is great. 

You may also use the command line for ```git```.

```bash
$ git init
$ git add .
$ git status
$ git commit -m "Messege"
$ git push origin master
```

![alt-tag](https://user-images.githubusercontent.com/25129399/38405234-88ce29c0-398c-11e8-9f41-d423db9515fc.png)


## Node.js

#### Running & Compiling automtically. Using nodemon
To compile and run automatically incase of changes made to ```*.cpp``` file, we may use nodemon. 
Make sure  ``` Node.js``` is already installed. Nodemon watches for changes in ```*  /dir``` and executes 
automatically in cases of changes. Nodemon can also be used to execute and monitor other programs.

```bash
$ npm install -g nodemon
```
Open one terminal and type the following, 

```bash
$ nodemon run.js 
```
#### For native compilation & Run.
With just one terminal open. ```run.js``` file contents are discussed below in Node.js Section. Used the ```--delay ``` option to avoid race conditions on reload. 

```bash
$ nodemon --delay 250ms run.js -e cpp
```
Open one terminal and type the following in the same ```dir``` as ```run.cpp```.

```bash 
$ nodemon --exec "g++ -O3 -W -pedantic -march=native -o run.exe" run.cpp
```
Open another terminal and write

```bash
$ nodemon --delay 2.5 --exec "run.exe" run.exe
``` 
You may also change the ```--delay 2.5``` option time to 1.
The Option```--delay 1``` makes sure that there is no race condition while run.exe 
is in use by the other nodemon process cause we are purposefully delaying it. 

See : 
![alt-tag](https://user-images.githubusercontent.com/25129399/38420190-96b42858-39c0-11e8-83f9-b43f487a331c.png)

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
If output is to be read to console as well after executing the .exe generated, use the below code. Addition to running, it will also open the output file generated and 
write it out to console. 

```javascript
var fs = require("fs");
var buf = new Buffer(1024);
var spawn = require('child_process').spawn;
var start = spawn('ls');
start.on('close', function(data){
  if(data === 0) {
    var compile = spawn('clang++',['run.cpp','-std=c++14','-O3','-Wall','-Wextra','-g','-fsanitize=address','-fno-omit-frame-pointer','-pedantic','-march=native','-v','-o','run.exe']);
    compile.stdout.on('data', (data) => {
    });
    compile.stderr.on('data', (data) => {
        console.log(String(data));
    });
    compile.on('close', (output) =>  {
      console.log("*** Compiling ***");
      console.log('Compilation done. Exited with code ' + output);
      var run = spawn('./run.exe', []);
      run.stdout.on('data', (output) => {
          console.log(String(output));
      });
      run.stderr.on('data', (output) => {
          console.log(String(output));
      });
      run.on('close', (output) => {
        console.log("**** Running .exe *****");
          console.log('Execution done. Exited with code ' + output);
          console.log("***** Output Data Read ******");
          console.log("Going to open Output file now");
          fs.open('output_buffer.in', 'r+', (err, fd) => {
             if (err) {
                return console.error(err);
             }
             console.log("Output data : ");
             fs.read(fd, buf, 0, buf.length, 0, (err, bytes) => {
                if (err){
                   console.log(err);
                }
                if(bytes > 0){
                   console.log(buf.slice(0, bytes).toString());
                }
                fs.close(fd, (err) => {
                   if (err){
                      console.log(err);
                   }
                   console.log("****** Output Read ******");
                });
             });
          });
      })
    })
  }
})
```

#### Covers Node.js tutorials as well. Check ```libjscript``` folder in ```Nodejs``` folder.
```bash
$ node -v
$ npm -v
$ sudo node ${Name-of-js-file.js}
```

## Using Clang for sanitization. 

Clang ```clang++``` gives us the oppurtunity to optimize our code and check for address and memory realted errors. 
It will show errors if there are undefined refernces and out of bound access of array. It also generates a verbose result of the error. 

For using clang for santization just add the ```-fsanitize=address```,```-fno-omit-frame-pointer``` & ```fsanitize=memory``` options. 

Modify the ```run.js``` file to use clang : 

```javascript
var compile = spawn('clang++',['run.cpp','-std=c++14','-O3','-Wall','-Wextra','-g','-fsanitize=address','-fno-omit-frame-pointer','-pedantic','-march=native','-v','-o','run.exe']);
```
Usage With clang : 

```C++
while(cin.good())
{
	getline(cin, word);
	input << word;
}
while(input >> line)
{
	wordlist.push_back(line);
}
struct TrieNode *root = getNode(); // A root node for trie created. 
for (auto i : wordlist)
{
    // Trying to insert all the words taken from the input file. input is a stringstream, word & line are of type basic_string<> string 
	insert(root, i);
    // Heap Memory Overflow should occur & clang correctly detects in during runtime. No compile time errors are generated. 
}
```    

No compile time errors are generated as ```Compilation done...```. Clang detects ```heap-buffer-overflow``` as expected. 
This code has a bug that it tries a to insert and the heap oveflows because so much memory can't be allocated.

```bash 
 "C:\\Program Files (x86)\\Microsoft
 Visual Studio\\2017\\Enterprise\\VC\\Tools\\MSVC\\14.13.26128\\bin\\HostX64\\x64\\link.exe" -out:run.exe -defaultlib:libcmt "-libpath:C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Enterprise\\VC\\Tools\\MSVC\\14.13.26128\\lib\\x64" "-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.16299.0\\ucrt\\x64" "-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.16299.0\\um\\x64" -nologo -debug -debug -incremental:no "C:\\Program Files\\LLVM\\lib\\clang\\6.0.0\\lib\\windows\\clang_rt.asan-x86_64.lib" "-wholearchive:C:\\Program Files\\LLVM\\lib\\clang\\6.0.0\\lib\\windows\\clang_rt.asan-x86_64.lib" "C:\\Program Files\\LLVM\\lib\\clang\\6.0.0\\lib\\windows\\clang_rt.asan_cxx-x86_64.lib" "-wholearchive:C:\\Program Files\\LLVM\\lib\\clang\\6.0.0\\lib\\windows\\clang_rt.asan_cxx-x86_64.lib" "C:\\Users\\Sumit\\AppData\\Local\\Temp\\run-10ef96.o"

Compilation done. Exited with code 0
=================================================================

==3232==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x121216383be0 at pc 0x7ff7fe404223 bp 0x00360d12f850 sp 0x00360d12f898
READ of size 8 at 0x121216383be0 thread T0

    #0 0x7ff7fe404222 in insert+0x222 (C:\Users\Sumit\Desktop\Runtime\run.exe+0x140004222)

    #1 0x7ff7fe405d09 in main+0x809 (C:\Users\Sumit\Desktop\Runtime\run.exe+0x140005d09)
    #2 0x7ff7fe466653 in __scrt_common_main_seh f:\dd\vctools\crt\vcstartup\src\startup\exe_common.inl:283

    #3 0x7ffaa6412783 in BaseThreadInitThunk+0x13 (C:\Windows\System32\KERNEL32.DLL+0x180012783)

    #4 0x7ffaa6e00d50 in RtlUserThreadStart+0x20 (C:\Windows\SYSTEM32\ntdll.dll+0x180070d50)


0x121216383be0 is located 8 bytes to the right of 216-byte region [0x121216383b00,0x121216383bd8)
allocated by thread T0 here:
    #0 0x7ff7fe464b71 in operator new C:\src\llvm_package_600-final\llvm\projects\compiler-rt\lib\asan\asan_new_delete.cc:92
    #1 0x7ff7fe4040d0 in insert+0xd0 (C:\Users\Sumit\Desktop\Runtime\run.exe+0x1400040d0)
    #2 0x7ff7fe405d09 in main+0x809 (C:\Users\Sumit\Desktop\Runtime\run.exe+0x140005d09)
    #3 0x7ff7fe466653 in __scrt_common_main_seh f:\dd\vctools\crt\vcstartup\src\startup\exe_common.inl:283
    #4 0x7ffaa6412783 in BaseThreadInitThunk+0x13 (C:\Windows\System32\KERNEL32.DLL+0x180012783)

    #5 0x7ffaa6e00d50 in RtlUserThreadStart+0x20 (C:\Windows\SYSTEM32\ntdll.dll+0x180070d50)

SUMMARY: AddressSanitizer: heap-buffer-overflow (C:\Users\Sumit\Desktop\Runtime\run.exe+0x140004222) in insert+0x222
Shadow bytes around the buggy address:
  0x043258ff0720: 00 00 00 00 00 00 00 00 00 00 00 fa fa fa fa fa
  0x043258ff0730: fa fa fa fa fa fa fa fa 00 00 00 00 00 00 00 00
  0x043258ff0740: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x043258ff0750: 00 00 00 fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x043258ff0760: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x043258ff0770: 00 00 00 00 00 00 00 00 00 00 00 fa[fa]fa fa fa
  0x043258ff0780: fa fa fa fa fa fa fa fa 00 00 00 00 00 00 00 00
  0x043258ff0790: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x043258ff07a0: 00 00 00 fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x043258ff07b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x043258ff07c0: 00 00 00 00 00 00 00 00 00 00 00 fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==3232==ABORTING

Execution done. Exited with code 1
```

![alt-tag](https://user-images.githubusercontent.com/25129399/38563096-b55b9e26-3cf9-11e8-88a8-bd270d0478cc.PNG)


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

Use the following commands.```-O3``` with level 3 optimization.

```bash
$ clang++ main.cpp -S -emit-llvm main.bc
$ clang++ main.cpp -S -emit-llvm -O3 main.bc
```
## Generating Assembly Language mnemonics

Use any the following commands.

```bash
$ clang++ main.cpp -S -O3 -o main.asm
$ gcc -g -c main.cpp -o main.o
$ objdump -d -M intel main.o
$ objdump -D -mcpu=<cpu-name> main.o
```
