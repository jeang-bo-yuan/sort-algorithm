####################################################
# 用來建置單元測試
####################################################
cmake_minimum_required(VERSION 3.28)
project(sort-unit-test)

add_subdirectory(deps/googletest)
enable_testing(true)

# 將所有的.h檔存進header_list中
file(GLOB header_list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

foreach(i ${header_list})
    # 將字串中的".h"去掉
    string(REPLACE ".h" "" i ${i})
    message(${i})

    # 一個可執行檔
    add_executable(${i}_executable test.cpp)

    if (MSVC)
        # 強制include標頭檔 + utf-8
        target_compile_options(${i}_executable PRIVATE "/FI ${i}.h" "/utf-8")
    else()
        # 強制include標頭檔（g++、Clang++版）
        target_compile_options(${i}_executable PRIVATE "-include ${i}.h")
    endif()

    # 連結至google test的main function
    target_link_libraries(${i}_executable GTest::gtest_main)

    add_test(
        NAME ${i}_test
        COMMAND ${i}_executable
    )
endforeach()
