/*****************************************************************//**
 * \file test.cpp
 * \author 蔣博元
 * \brief 用來測試排序演算法是否正常執行的程式碼
 * \details 會用到的巨集 SORTING_FUNC ，它們定義在實作排序演算法的標頭中
 *********************************************************************/
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

// 為了避免語法分析器報error
#ifndef SORTING_FUNC
	#define SORTING_FUNC(A) std::sort(A.begin(), A.end())
	#define NAME "Standard Library - Sort"
#endif

// 測試能否在空陣列上執行
TEST(Sorting, Empty) {
	std::vector<int> test;
	ASSERT_NO_THROW(SORTING_FUNC(test)) << "Failed to run on empty vector";
}

// 隨機生成陣列並測試
TEST(Sorting, RandomArray) {
	std::vector<int> test;

	srand(time(NULL));
	for (int t = 10; t--;) {
		// create a random array
		test.resize(rand());
		for (int& i : test) i = rand();

		// sorting
		SORTING_FUNC(test);

		// verify that the array is non-decreasing
		for (size_t i = 1; i < test.size(); ++i) {
			ASSERT_TRUE(test[i - 1] <= test[i]) << "Sorting Error";
		}
	}
}
