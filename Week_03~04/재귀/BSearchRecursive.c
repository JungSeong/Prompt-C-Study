#include <stdio.h>

int BSearch(int arr[], int first, int last, int target)
{
    int mid = (first+last)/2;

    if (first > last)
    {
        return 0;
    }

    if (arr[mid] < target)
    {
        BSearch(arr, mid+1, last, target);
    }
    else if (arr[mid] > target)
    {
        BSearch(arr, first, mid-1, target);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int sorted_arr[] = {1, 3, 5, 7, 9};
    printf("BSearch index : %d\n", BSearch(sorted_arr, 0, sizeof(sorted_arr)/sizeof(int)-1, 7));
    printf("BSearch index : %d\n", BSearch(sorted_arr, 0, sizeof(sorted_arr)/sizeof(int)-1, 4));
    printf("BSearch index : %d\n", BSearch(sorted_arr, 0, sizeof(sorted_arr)/sizeof(int)-1, 9));
}