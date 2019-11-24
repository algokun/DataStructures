#include "stdio.h"
#include "stdlib.h"

int stack[100], top = -1;

void push(int val, int n){
    if (top == n)
    {
        printf("\nOverFlow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop(){
    if (top == -1)
    {
        printf("\n UnderFlow");
        return 0;
    }
    else{
        return stack[top--];
    }
}

int peek(){
    if (top == -1)
    {
        printf("\n UnderFlow");
        return 0;
    }
    else
    {
        return stack[top];
    }
    
}

void display(int size){

    for (int i = 0; i < size; i++)
    {
        printf("%d \t",stack[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    int size, value;
    printf("Enter size of Stack <100 : \n");
    scanf("%d",&size);
    
    printf("Enter %d elements\n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&value);
        push(value,size);
    }

    printf("Elements in the Stack\n");
    display(size);

    return 0;
}
