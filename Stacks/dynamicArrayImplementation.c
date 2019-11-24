// From GeeksForGeeks
#include "stdio.h"
#include "stdlib.h"

// Stack type 
typedef struct stackType
{ 
    int top; 
    int capacity; 
    int* array; 
} Stack; 
  
// Stack Operations 
Stack* createStack( int capacity ) 
{ 
    Stack* stack = (Stack*) malloc(sizeof(Stack)); 
    int size;
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    size = stack->capacity * sizeof(int);
    stack->array = (int*) malloc(size); 
  
    if (!stack->array) 
        return NULL; 
    return stack; 
} 

int isEmpty(Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

int peek(Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 

int pop(Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return -9898899; 
} 

void push(Stack* stack, int value) 
{ 
    stack->array[++stack->top] = value;
} 

void display(Stack* stack){
    int i;
    for (i = stack->capacity - 1; i >= 0; i--)
    {
        printf("|\t%d\t|\n",stack->array[i]);
    }
    printf("|_______________|");
}

int main() 
{ 
    int n, value;
    char choice;
    Stack* stack = NULL;
    printf("Enter the capacity for Stack:");
    scanf("%d",&n);
    stack = createStack(n);

    printf("\nEnter %d Elements:",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(stack, value);
    }
    
    display(stack);

    printf("\nDisplay Elements : [Y/N]:");
    choice = getchar();

    switch (choice)
    {
    case 'Y':
        display(stack);
        break;
    case 'N':
        exit(0);
        break;
    default:
        break;
    }

    return 0;
} 