#include <stdio.h>
#include <math.h>

void Hanoi(int num, int from, int by, int to)
{
    if (num == 1)
    {
        printf("%d %d\n", from, to);
    }

    else
    {
        Hanoi(num-1, from, to, by);
        printf("%d %d\n", from, to);
        Hanoi(num-1, by, from, to);
    }
}

int main()
{
    int input;
    scanf("%d", &input);

    unsigned long long num = pow(2,input)-1;
    printf("%llu\n", num);

    if (input <= 20)
    {
        Hanoi(input, 1, 2, 3);
    }
}