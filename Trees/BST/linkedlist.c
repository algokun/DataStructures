#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node;
node* root=NULL;
void insert(void);
void print(void);
void length(void);
void main()
{
    int choice;
    while(1)
    {
        printf("1.insert\n");
        printf("2.print\n");
        printf("3.length\n");
        printf("4.exit\n");  
        printf("enter your choice\n");
        scanf("%d",&choice);  
    switch(choice)
    {
        case 1:insert();
               break;
        case 2:print();
               break;
        case 3:length();
               break;
        case 4:exit(1);
               break;
        default:printf("invalid");
    }
}
}
void insert()
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    printf("enter the data");
    scanf("%d",&temp->data);
    if(root==NULL)
    {
        temp=root;
    }
    else
    {
        node* p;
        p=root;
        if(p->link!=NULL)
        {
            p=p->link;
            
        }
        p->link=temp;
    }
}
void print()
{
    node* temp;
    temp=root;
        while(temp->link!=NULL)
        {
            printf("elemnts in the list are->%d",temp->data);
            temp=temp->link;
        }
}
void length()
{
      int count;
      node* temp;
      temp=root;
      while(temp->link!=NULL)
      {
          count++;
          temp=temp->link;
      }
      printf("length in the list are %d",count);
}