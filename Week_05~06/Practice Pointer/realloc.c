#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, total_len;
	int arr_len = 3, add_len = 2;
	int* ptr_arr;
	
	ptr_arr = (int*) malloc(arr_len * sizeof(int));	// 메모리의 동적 할당 
	
	if (ptr_arr == NULL)	// 메모리의 동적 할당이 실패할 경우
	{
		printf("메모리의 동적 할당에 실패했습니다.\n");
		exit(1);
	}

    for (int i=0; i<arr_len; i++)
    {
        scanf("%d", ptr_arr + i);
    }
	
	printf("동적으로 할당받은 메모리의 초기값은 다음과 같습니다.\n");
	for (i = 0; i < arr_len; i++)
	{
		printf("%d ", ptr_arr[i]);
	}
	
	total_len = arr_len + add_len;
	ptr_arr = (int*) realloc(ptr_arr, (total_len * sizeof(int)));	// 메모리의 추가 할당 
	
	if (ptr_arr == NULL)	// 메모리의 추가 할당에 실패할 경우
	{
		printf("메모리의 추가 할당에 실패했습니다.\n");
		exit(1);
	}
			
	printf("\n추가로 할당받은 메모리의 초기값은 다음과 같습니다.\n");
	for (i = 0; i < total_len; i++)
	{
		printf("%d ", ptr_arr[i]);
	}
	
	free(ptr_arr);			// 동적으로 할당된 메모리의 반환 
	
	return 0;
}