#include <vector>

#define SORTING_FUNC selection_sort
#define NAME "selection sort"

//  升冪排序
void selection_sort(std::vector<int>& A) {
	for (size_t i = 0; i < A.size(); ++i) {
		size_t min_i = i;

		// 找最小的元素
		for (size_t j = i + 1; j < A.size(); ++j) {
			if (A[j] < A[min_i]) min_i = j;
		}

		// 將最小元素和第i項交換
		if (i != min_i) std::swap(A[i], A[min_i]);
	}
}
