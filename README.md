# stmp
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d89bb42013a048638ed47b9adc371692)](https://www.codacy.com/app/ParadoxZero/stmp?utm_source=github.com&utm_medium=referral&utm_content=ParadoxZero/stmp&utm_campaign=badger)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) [![Build Status](https://travis-ci.org/ParadoxZero/stmp.svg?branch=master)](https://travis-ci.org/ParadoxZero/stmp)

Simple macro processor. It will expand MACROs defined in source code and create a new source file.

#### Notice
stmp will change the layout of code, especially spacing and tabs hence it should not be used along with languages like python.

## Macro Definition Language Syntax

The syntax of defining a macro:

```
  <macro_name> MACRO <arg1> <arg2> ..... <arg n>
  statement1
  statement2
    .   .
    .   .
    .   .
  MEND
```

Example:

```c
  add_and_check MACRO arg1 arg2
  add(arg1,arg2);
  check(arg2,arg1);
  MEND

  sum MACRO a b
  a=a+b;
  MEND

  void test_function(int a, int b){
      int c=5;
      add_and_check a b
      sum c b
      return c;
  }
```

stmp would yield an output:
```c
void test_function ( int a ,  int b )  {  
int c = 5 ;  
add ( a , b ) ;
check ( b , a ) ; 

c = c + b ;

return c; 
 }  
```
### Comments

stmp recognizes comments and doesn't expand them.
Currently **only line comments supported**.

Syntax of comment:
  `#` or `//`

eg:
```
int c = 6;
//will be ignored
# will be ignored
```

If comment is placed within the macro **it will be copied** when expanded.

# Why use MACRO ?

MACROs are usefull when you want to manupulate source code. Repeat certain lines of code, but each copy is slightly different from the last.

For example, suppose you want the following functions:
```cpp
double getDoubleSize () { 
  return sizeof(type); 
} 

int getIntSize () { 
  return sizeof(type); 
} 

void printDouble ( double x ) { 
  printf( "%lf" , x ); 
} 

void printInt ( int x ) { 
  printf( "%d" , x ); 
} 
```

Instead of writting the repeative code simply use MACRO:

```
create_size_function getDoubleSize double
create_size_function getIntSize int
create_print_function printDouble "%lf" double
create_print_function printInt "%d" int
```
 
## How to use

* Basic usage:
```
  $ ./stmp source_file.extension
```

* Help
```
  $ ./stmp -h
  $ ./stmp --help
  Usage:
    stmp [FLAGS]... [PATH]

  Flags available to use:
  1) -v, --version    Output version details and exit.
  2) -h, --help    Output this help and exist.

  Exapmle: stmp example.asm
```
## How to build

### prerequisite

* CMake
* Gcc/Clang

1) Download source

```bash
  $ git clone https://github.com/ParadoxZero/stmp.git
  $ cd stmp
```

2) Create build directory
```bash
  $ mkdir build  
  $ cd build
```

3) Build
```bash
  $ cmake ..
  $ make
```

## How to run tests

```bash
  $ chmod +x run_test.sh
  $ ./run_test.sh
```
## Contributing

Feel free to send a pull request.

for any queries contact me: sidhin.thomas@gmail.com
