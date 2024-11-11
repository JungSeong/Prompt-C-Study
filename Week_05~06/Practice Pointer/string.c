#include <stdio.h>

int main()
{
    char str1[10] = "language";
    char *str2 = "programming";

    printf("str2에 저장되는 값 = 'programming' 이라는 배열의 주소 값, %p %p", str2, "programming");
    str2 = "macintoch"; // 'macintoch'라는 배열의 주소가 str2에 저장된다.
    printf("\n%s %s", str2, "macintoch");
}