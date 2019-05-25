#include "BS.h"
#include <time.h>


int main() {
	Heap hp;
	int arr[] = { 2,6,7,3,9,1,4,0,5,8 };
	InitHeap(&hp, arr, 10,Less);
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
	system("pause");
	return 0;
}