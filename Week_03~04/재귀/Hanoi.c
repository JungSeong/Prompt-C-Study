#include <stdio.h>

int Hanoi(int num, char from, char by, char to, int total)
{
    total++;
    if (num == 1)
    {
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
    }

    else
    {
        total = Hanoi(num-1, from, to, by, total);
        printf("원반 %d을 %c에서 %c로 이동\n", num, from, to);
        total = Hanoi(num-1, by, from, to, total);
    }
    return total;
}

int main()
{
    int total = 0;
    printf("총 옮긴 횟수 : %d\n", Hanoi(4, 'A', 'B', 'C', total));
}