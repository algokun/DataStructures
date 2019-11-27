#include "stdio.h"
#include "stdlib.h"

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[] , int n){
    
    for (int i = 0; i < n - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if(A[j] < A[iMin])
                iMin = j;
        }
        swap(&A[i], &A[iMin]);
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {2 , 7 ,45,1,3,34};
    int size = sizeof(A)/sizeof(A[0]);
    selectionSort(A , size);
    for (int i = 0; i < size; i++)
    {
        printf("%d \t",A[i]);
    }
    
    return 0;
}
