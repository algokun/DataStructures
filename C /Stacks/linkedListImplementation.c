#include "stdlib.h"
#include "stdio.h"

typedef struct nodeType {
    int data;
    struct nodeType* next;
} Node;

Node* top;

Node* createNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(int data){
    Node* tmp;
    tmp = createNode(data);

    if (!tmp)
    {
        printf("\nHEAP OVERFLOW");
        exit(1);
    }
    
    tmp->next = top;
    top = tmp;
}

int isEmpty() 
{ 
    return top == NULL; 
} 

int peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 

void pop(){
    Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        printf("\nSTACK UNDERFLOW");
        exit(1); 
    } 
    else { 
        temp = top; 
        top = top->next; 
        temp->next = NULL; 
        free(temp); 
    } 
}

void display()  
{ 
    Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        printf("\nSTACK UNDERFLOW");
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            printf(" %d ",temp->data);
  
            // assign temp link to temp 
            temp = temp->next; 
        } 
    } 
} 

int main() 
{ 
    // push the elements of stack 
    push(11); 
    push(22); 
    push(33); 
    push(44); 
  
    // display stack elements 
    display(); 
  
    // print top elementof stack 
    printf("\nTop element is %d\n",peek()); 
  
    // delete top elements of stack 
    pop(); 
    pop(); 
  
    // display stack elements 
    display(); 
  
    // print top elementof stack 
    printf("\nTop element is %d\n",peek());
    return 0; 
  
} 