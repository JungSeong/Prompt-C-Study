#include <stdio.h>
#define N 7

void sort(int sort[N])
{
    int temp;
    
    // 정렬 프로그램
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if (sort[i] > sort[j])
            {
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }

    // 중복된 값은 출력하지 않는 프로그램
    for (int i=0; i<N; i++)
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
    int arr[N];
    printf("길이가 7인 배열 하나를 입력하세요 : ");
    
    for (int i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr);
    return 0;
}