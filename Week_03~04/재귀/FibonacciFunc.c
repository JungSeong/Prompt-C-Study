#include <stdio.h>

int Fibo(int num)
{
    if(num==0)
    {
        return 0;
    }
    else if(num==1)
    {
        return 1;
    }
    else
    {
        return Fibo(num-1) + Fibo(num-2);
    }
}

int main()
{
    for (int i=0; i<15; i++)
    {
        printf("%d ", Fibo(i));
    }
    printf("\n");
}