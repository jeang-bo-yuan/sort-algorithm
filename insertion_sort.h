#include <vector>

#define SORTING_FUNC insertion_sort
#define NAME "insertion sort"

// 升冪排序
void insertion_sort(std::vector<int>& A) {
	for (size_t i = 1; i < A.size(); ++i) {
		// [0, i - 1]是已排序好的陣列
		// 每次迴圈，要將第i項插入排序好的陣列中適當的位置
		int tmp = A[i];
		size_t insert_here = i;

		// 如果左邊的元素比較大，則往右移
		while (insert_here > 0 && A[insert_here - 1] > tmp) {
			A[insert_here] = A[insert_here - 1];
			--insert_here;
		}

		A[insert_here] = tmp;
	}
}
