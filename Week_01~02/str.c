#include <stdio.h>
#include <string.h>

int main(){
    char st[15] = "";
    char st2[5] = {'a', 'b', 'c', 'd', '\0'};

    scanf("%s", st);

    printf("%s %d\n", st, strlen(st));
    printf("%s %d\n", st2, strlen(st2));
}