# About

使用C++實作排序演算法，以升冪排序為例。

# How to Build Unit Test

Step1: Clone Repository

```sh
git clone https://github.com/jeang-bo-yuan/sort-algorithm
cd sort-algorithm

# clone googletest
git submodule init
git submodule update
```

Step2: 建置

```sh
mkdir build
cd build

# configure & generate
cmake ..

# build
cmake --build .
```

Step3: 執行ctest

```sh
ctest

# 如果是用MSVC Compiler則要加上-C參數
ctest -C Debug
```
