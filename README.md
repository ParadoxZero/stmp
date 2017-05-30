# stmp
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
