#include <vector>

#define SORTING_FUNC bubble_sort
#define NAME "bubble sort"

//  升冪排序
void bubble_sort(std::vector<int>& A) {
	if (A.size() <= 1)  return;

	for (size_t end = A.size() - 1; end > 0; --end) {
		for (size_t i = 1; i <= end; ++i) {
			// 左比右大則交換
			if (A[i - 1] > A[i]) std::swap(A[i - 1], A[i]);
		}
	}
}
