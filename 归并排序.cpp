#include <cstdio>
using namespace std;

int count;
void merge_sort(int* A, int x, int y, int* T) {
	if(y-x > 1) {
		int m = x + (y-x)/2;
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);
		merge_sort(A, m, y, T);
		while(p < m || q < y) {
			if(q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];
			else {
				T[i++] = A[q++];
				count += m-p;
			}
		}
		for(i = x; i < y; i++) A[i] = T[i];
	}
}

int main() {
	int a[100] = {5,4,3,2,1};
	int t[100] = {0};
	merge_sort(a, 0, 5, t);
	printf("%d\n", count);
	return 0;
}
