// From GeeksForGeeks
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// Stack type 
typedef struct stackType
{ 
    int top; 
    unsigned capacity; 
    int* array; 
} Stack; 
  
// Stack Operations 
Stack* createStack( unsigned capacity ) 
{ 
    Stack* stack = (Stack*) malloc(sizeof(Stack)); 
  
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
  
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) 
        return NULL; 
    return stack; 
} 

int isEmpty(Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

char peek(Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 

char pop(Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 

void push(Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 

int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
}

int getPrecedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 

int infixToPostfix(char* exp){
    int i,k;

    Stack* stack = createStack(strlen(exp));
    if (!stack)
    {
        return -1;
    }
    
    for (k=-1, i = 0;exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output. 
        if (isOperand(exp[i])) 
            exp[++k] = exp[i];

        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (exp[i] == '(') 
            push(stack, exp[i]); 

        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                exp[++k] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1; // invalid expression              
            else
                pop(stack); 
        } 

        else // an operator is encountered 
        { 
            while (!isEmpty(stack) && getPrecedence(exp[i]) <= getPrecedence(peek(stack))) 
                exp[++k] = pop(stack); 
            push(stack, exp[i]); 
        } 
    }
    // pop all the operators from the stack 
    while (!isEmpty(stack)) 
        exp[++k] = pop(stack ); 
  
    exp[++k] = '\0'; 
    printf( "\n%s\n", exp ); 
}

// Driver program to test above functions 
int main() 
{ 
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
} 