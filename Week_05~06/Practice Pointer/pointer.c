#include <stdio.h>

int main()
{
	int n = 10;
	int *ptr = &n;
	int *ptr_2 = NULL;
	int **pptr = NULL;

	ptr_2 = &n;
	pptr = &ptr;

	printf("%p %p %p", &n, &ptr, &pptr);
	printf("\n포인터 변수 ptr에 저장된 값 == 변수 n의 주소, %p %p", ptr, &n);
	printf("\n포인터 변수 ptr_2에 저장된 값 == 변수 n의 주소, %p %p", ptr_2, &n);
	printf("\n포인터 변수 pptr에 저장된 값 == 포인터 변수 ptr의 주소, %p %p", pptr, &ptr);

	// 배열의 이름은 그 자체로 메모리에 올라간 배열의 시작 주소를 가르키는 상수 값이다.
	int arr[5] = {1,2,3,4,5};
	int *parr = arr;
	printf("\n포인터 변수 parr에 저장된 값 == 배열 arr의 주소, %p %p", parr, arr);
	printf("\narr[0] : %d %d %d, arr[1] : %d %d %d", arr[0], *(arr+0), *(parr+0), arr[1], *(arr+1), *(parr+1));
	printf("\n%d %d %d == %d %d %d", arr[0], arr[1], arr[2], parr[0], parr[1], parr[2]);
	printf("\n%d %d %d == %d %d %d", *arr, *(arr+1), *(arr+2), *parr, *(parr+1), *(parr+2));
	printf("\n배열의 arr의 크기 : %ld, 포인터 배열 parr의 크기 : %ld", sizeof(arr), sizeof(parr));
}