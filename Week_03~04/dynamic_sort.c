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

    // 중복된 값은 제외하고 출력
    for (int i=0; i<size; i++)
    {
        if (sort[i] != sort[i+1])
        {
            printf("%d ", sort[i]);
        }
    }

    printf("\n");
}

int main()
{
    int size;
    printf("배열의 사이즈를 입력하세요 : ");
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size);

    printf("배열을 입력하세요 : ");

    for (int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, size);
    free(arr);
    
    return 0;
}