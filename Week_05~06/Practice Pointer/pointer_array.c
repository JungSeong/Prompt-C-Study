#include <stdio.h>

int main()
{
    int i, arr_len;
    int num_1 = 10, num_2 = 20, num_3 = 30;
    int *arr[3] = {&num_1, &num_2, &num_3};

    // arr[0] : num_1의 주소를 가르킴, arr[1] : num_2의 주소를 가르킴...
    printf("%p %p\n", &num_1, arr[0]);
    printf("%ld %ld\n", sizeof(arr), sizeof(arr[0]));

    for (int i=0 ; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d ", *arr[i]);
    }
}