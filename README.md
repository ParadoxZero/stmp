# stmp
Simple macro processor. It will expand MACROs defined in source code and create a new source file.

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

```
  $ git clone https://github.com/ParadoxZero/stmp.git
  $ cd stmp
```

2) Create build directory
```
  $ mkdir build  
  $ cd build
```

3) Build
```
  $ cmake ..
  $ make
```
