#include <stdio.h>

int main()
{
    int num = 10;
    void* ptr_num = &num;

    printf("%d %d", num, *(int*) ptr_num);
    *(int*)ptr_num = 20;
    printf("\n%d %d", num, *(int*) ptr_num);
}