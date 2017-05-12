# C Data Structures
A small collection of data structures that I've used for a few different school projects.

## Usage
Download the source code, navigate to the root directory of the data structure you would like to use, copy the header files from `include/` and source files from `src/` to your project, and then add them to your `Makefile` or compile line. See the the data structure's `Makefile` to determine dependencies, or just look at the `#include` statements in the files.
e.g.
```
$ cd queue/
$ cp src/*.c include/*.h path/to/your/project/
$ vim path/to/your/project/Makefile
```

## Examples
The test suites for the data structures, named `path/to/data/structure/root/src/main.c`, can be used as examples.

## Testing
To run the test suite for a data structure, navigate to the root directory of the data structure you would like to test, type make, and run the executable.
e.g.
```
$ cd queue/
$ make
$ ./queue
```
