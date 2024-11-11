#include <stdio.h>
#include <wchar.h>
#include <locale.h>
 
int main() 
{   
    int hour = -20;
    hour %= 3;

    printf("%d", hour);

    return 0;
}