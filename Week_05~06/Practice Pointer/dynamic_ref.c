#include <stdio.h>
#include <stdlib.h> // malloc 함수가 포함된 헤더 파일

void sort(int *sort, int size)
{
    int temp;
    
    // 정렬 프로그램
    for (int i=0; i<size; i++)
    {
        for (int ii=i+1; ii<size; ii++)
        {
            if (*(sort + i) > *(sort + ii))
            {
                temp = *(sort + i);
                *(sort + i) = *(sort + ii);
                *(sort + ii) = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("배열의 사이즈를 입력하세요 : ");
    scanf("%d", &size);

    // int* arr = (int*)malloc(sizeof(int) * size);
    int* arr = (int*)calloc(sizeof(int), size);

    printf("배열을 입력하세요 : ");

    for (int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, size);

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    
    return 0;
}