#include <stdio.h>

int main() {
    int n;
    printf("자연수 하나를 입력하세요 : ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++){
        for (int j=0 ; j<=2*n-1 ; j++){
            if (j >= (2*(n-i)+1)/2 && j <= 2*n -(2*(n-i)+1)/2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
	}
}