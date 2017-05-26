# stmp
Simple macro processor. It will expand MACROs defined in source code and create a new source file.

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
