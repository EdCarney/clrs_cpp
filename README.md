# Description
Implmentation of algorithms from CLRS 3rd edition in C++. CMake is used to build, [googletest](https://github.com/google/googletest) is used for testing.
CMake will output compile commands by default (verified functionality with clangd LSP).

# Building
This repo uses cmake to build. Execute the following from the repo parent directory:

```
mkdir build
cd build
cmake ..
make
```

# Testing
Testing is done via [googletest](https://github.com/google/googletest). Execute the following from the repo parent directory (assuming project has already been built);

```
cd build
./test/CLRS_CPP_TESTS
```
