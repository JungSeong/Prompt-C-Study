#include <stdio.h>

int Factorial(int num)
{
    if (num > 0)
    {
        return num * Factorial(num-1);
    }
    
    else
    {
        return 1;
    }
}

int main()
{
    printf("0! : %d\n", Factorial(0));
    printf("1! : %d\n", Factorial(1));
    printf("2! : %d\n", Factorial(2));
    printf("3! : %d\n", Factorial(3));
    printf("4! : %d\n", Factorial(4));
    printf("5! : %d\n", Factorial(5));
}