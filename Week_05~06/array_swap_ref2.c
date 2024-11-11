#include <stdio.h>
#include <stdlib.h>

#define True 1

void swap(int *arr_a, int *arr_b, int *size_a, int *size_b)
{
    int temp;

    if (*size_a > *size_b)
    {
        *size_b = *size_a;
        arr_b = (int*)realloc(arr_b, sizeof(int)* *size_b);
    }

    else
    {
        *size_a = *size_b;
        arr_a = (int*)realloc(arr_a, sizeof(int)* *size_a);
    }

    for (int i=0; i<*size_a; i++)
    {
        printf("%p\n", arr_a + i);
    }

    for (int i=0; i<*size_a; i++)
        {
            temp = *(arr_a + i); // temp = *(*(arr_a)+i);
            *(arr_a + i) = *(arr_b + i);
            *(arr_b + i) = temp;
        }
}

int main()
{
    int size_a;
    int size_b;

    int *arr_a = NULL;
    int *arr_b = NULL;

    while(True)
    {
        printf("두 배열의 크기를 입력하세요. : ");
        scanf("%d %d", &size_a, &size_b);

        if (size_a == 0 || size_b == 0)
        {
            printf("배열의 크기는 0이 될 수 없습니다.\n");
            continue;
        }

        arr_a = (int*)malloc(sizeof(int) * size_a);
        arr_b = (int*)malloc(sizeof(int) * size_b);

        for (int i=0; i<size_a; i++)
        {
            printf("%p\n", arr_a + i);
        }

        if (arr_a == NULL || arr_b == NULL)
        {
            printf("메모리 할당에 실패하였습니다.\n");
            return -1;
        }

        /*
        1. 만약 size_a 값으로 0이 입력되었다고 한다면, arr_a는 컴파일러에 따라 NULL을 반환할 수도, 어떤 유효한 주소값을 반환할 수도 있다.
        2. 메모리가 부족할 경우 malloc 메모리 할당이 실패할 수 있다.
        */

        printf("배열 A를 입력하세요 : ");
        
        for (int i=0; i<size_a; i++)
        {
            // scanf("%d", &arr_a[i]);
            scanf("%d", arr_a+i);
        }

        printf("배열 B를 입력하세요 : ");

        for (int i=0; i<size_b; i++)
        {
            // scanf("%d", &arr_b[i]);
            scanf("%d", arr_b+i);
        }

        break;   
    }

    swap(arr_a, arr_b, &size_a, &size_b);

    printf("=== SWAP 이후의 배열 ===\n");

    for (int i=0; i< size_a; i++)
    {
        printf("%d ", arr_a[i]);
        // printf("%d ", *(arr_a + i));
    }

    printf("\n");

    for (int i=0; i< size_b; i++)
    {
        printf("%d ",arr_b[i]);
        // printf("%d ", *(arr_b + i));
    }

    printf("\n");

    free(arr_a);
    free(arr_b);
}