#include "stdio.h"
#include "stdlib.h"

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[] , int n){
    int flag = 0;
    for (int k = 1; k < n - 1; k++)
    {
        flag = 0;
        for (int i = 0; i < n - k - 1; i++)
        {
            if(A[i] > A[i+1]){
                swap(&A[i], &A[i+1]);
                flag = 1;
                }
        }
        if (flag == 0)
            break;
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {2 , 7 ,45,1,3,34};
    int size = sizeof(A)/sizeof(A[0]);
    bubbleSort(A , size);
    for (int i = 0; i < size; i++)
    {
        printf("%d \t",A[i]);
    }
    
    return 0;
}
