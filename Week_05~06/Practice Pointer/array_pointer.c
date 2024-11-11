 #include <stdio.h>
 
 int main()
 {
    int darr[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int (*parr)[3] = darr;

    printf("\ndarr[0][0]의 주소 == arr[0], %p %p", &(darr[0][0]), darr[0]);
    printf("\ndarr[1][0]의 주소 == arr[1], %p %p", &(darr[1][0]), darr[1]);
    printf("\ndarr[1][1] == *(darr[1]+1), %d %d", darr[1][1], *(darr[1]+1));
    printf("\ndarr[1][1] == parr[1][1], %d %d", darr[1][1], parr[1][1]);
 }
