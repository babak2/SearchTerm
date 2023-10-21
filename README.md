# SearchTerm

The SearchTerm program is designed to search for matches of a search term (substring) in a source text file. It takes a command-line argument specifying the input file path, which contains the source text and the search term.

## Program Requirements

- The program is intended to run on Linux (Ubuntu).
- The input file should be a text file (.txt) with a specific format.
- The source text lines specify the <source_text>, and the last line specifies the <search_term>.
- The program searches the <source_text> for matches of the <search_term> and outputs the matching lines.

## Input File Format

The input file should have the following format:
```
<source_text>

<source_text>

<source_text>

<search_term>
```

- The <source_text> consists of lines of strings, with each line containing three words embedded in symbols, numbers, and spaces.


- The <search_term> is always on the last line and contains a single word.

## Match Criteria

A line from the source text is considered a match if any word on the line contains the search term as a substring.

## Output Format

The program outputs the matching lines to the OS Terminal. Each line is formatted as a single-space separated square-bracket-enclosed list.

- Correct Format: 

`[this is ok]`

- Incorrect Formats: 

`[this, no, good]`

`{this no good}`

`[this,no,good]`

`[ this no  good  ]`

If multiple lines match, the program outputs them in the order they appear in the source text.

## Examples

Here are some examples to demonstrate the program's functionality:

### Example 1:

Input File:

```
cat sees me
mary likes trees
up the hill
ee
```


Output:

`[cat sees me]`

`[mary likes trees]`


### Example 2:

Input File:

```
"Alice was beginning...
to_get9_!very
1111tired1111of1111sitting1111
by her_sister.
on9the bank,
and""of""having
nothing to do!!!
er
```

Output:

`[to get very]`

`[by her sister]`


## To Build

`g++` is the default compiler.


```
make
```
For more details please refer to the `Makefile`


## To Run

If you are already in ./build/bin directory (i.e. used cd to change to this directory)

```
./search_term  <path_to_txt_file>
```

Example: 

`./search_term  ../../input_files/input_alice.txt`


Otherwise, if you are in your project/working directory: 

```
./build/bin/search_term  <path_to_txt_file>
```

### Input file examples

There are a few input .txt files for use and testing in the `/input_files` directory



## To Test
We use the [Catch2](https://github.com/catchorg/Catch2) framework.

1. Build tests:
```
make test
```

2. Run all tests:
```
./build/bin/test
```

3. List all tests:
```
./build/bin/test -l
```

4. Run a specific test (example):
```
./build/bin/test [validateInputFile:empty-file]
```

## Dependencies
C++ Libraries and the version installed on the development machine:

### .hpp Dependencies
These are header-only libraries that are included as part of this project. No installation is required.

- [Catch2](https://github.com/catchorg/Catch2), v2.1.2, a C++ test framework. `./test/third_party/`



## Assumptions

Currently, only .txt files can be used as input files, but the program behaves properly when the wrong file type (or empty file, or file with only one line, ...) is used as input.


  
## run on Windows (not tested!)

This program is written on Ubuntu 20.04.5 LTS. It may be still possible to run the program on Windows with a few considerations and modifications you may need to make to ensure the program runs correctly.

Here are some steps you can follow to run a program on Windows that was originally written for Ubuntu:

- Install a compatible development environment: On Windows, you will need to install a development environment that supports compiling and running C++ programs. One popular option is MinGW (Minimalist GNU for Windows), which provides a Windows port of the GNU Compiler Collection (GCC) along with other necessary tools. Install MinGW or any other compatible development environment on your Windows system.

- Modify the Makefile: The Makefile may need to be modified to accommodate the differences between the build systems on Ubuntu and Windows. Specifically, you may need to update the compiler flags, library paths, and other system-specific configurations to match the Windows environment. Ensure that the Makefile is updated to work with the Windows development environment you installed.

- Check for system-specific code: Review the program's code and dependencies for any system-specific code that may be incompatible with Windows. For example, if your program uses Linux-specific system calls or libraries, you may need to find equivalent Windows functions or libraries.

- Compile the program: Use the modified Makefile to compile the program on your Windows system. Open a terminal or command prompt, navigate to the program's directory, and run the appropriate make command (e.g., make or make all). This will compile the program using the Windows development environment.

-  Resolve platform-specific issues: Test the program on Windows and address any platform-specific issues that may arise. Debug any errors or inconsistencies that are specific to the Windows environment. This may involve adjusting code, modifying library dependencies, or addressing compatibility issues.

- Run the program: Once the program is successfully compiled, you should be able to run it on Windows. Execute the program from the command prompt or terminal, providing any necessary command-line arguments or inputs as required.



## License

The SearchTerm program is licensed under the GNU GENERAL PUBLIC LICENSE. See LICENSE for more information.


## Author 

Babak Mahdavi Ardestani

babak.m.ardestani@gmail.com
