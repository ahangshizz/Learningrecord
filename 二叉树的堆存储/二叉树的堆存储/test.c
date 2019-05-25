#include "heap.h"
#include <time.h>
int main() {
	Heap hp;
	srand((unsigned)time(NULL));
	int arr[20];
	for (int i = 0; i < 20; ++i) {
		arr[i] = rand() % 21;
	}
	InitHeap(&hp, (HPDataType*)arr, 20);
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
	system("pause");
	return 0;
}