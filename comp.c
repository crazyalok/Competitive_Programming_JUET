#include<stdio.h>
#include<stdlib.h>
struct node
{
    int INFO;
    struct node *NEXT;
};
struct node *append(struct node *START,int info)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=START;
    if(START==NULL)
    {
        START->INFO=info;
        START->NEXT=NULL;
        return START;
    }
    while(temp->NEXT!=NULL)
    temp=temp->NEXT;
    temp->NEXT=newnode;
    newnode->INFO=info;
    newnode->NEXT=NULL;
    return START;
}
struct node *createnode(int n)
{
    int info,i;
struct node *New_node,*temp,*START=NULL;
if (n<1)
{
    return NULL;
}
else
{
    START=(struct node*)malloc(sizeof(struct node));
    if (START==NULL)
   {

     printf("memory cannot be allocated.");
   exit(0);
   }
    else
    {
        printf("enter value of node: ");
        scanf("%d",&info);
        START->INFO=info;
        START->NEXT=NULL;
        temp=START;
        for (i=2;i<=n;i++)
        {
            New_node=(struct node*)malloc(sizeof(struct node));
            if(New_node==NULL)
           {
                printf("memory cannot be allocated.");
                exit(0);
           }
           else
           {
               printf("enter value of node: ");
        scanf("%d",&info);
               New_node->INFO=info;
               New_node->NEXT=NULL;
               temp->NEXT=New_node;
               temp=temp->NEXT;
           }
        }
    }
}
return START;
}
void display_node(struct node *START)
{
     struct node *temp=START;
    if (START==NULL)
    {
        printf("linked list is empty.");
        exit(0);
    }
    else
    {
    while(temp!=NULL)
    {
        printf("%d",temp->INFO);
        temp=temp->NEXT;
    }
    printf(" NULL");
    }
}
int main()
{
    int n,info;
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    struct node *START=createnode(n);
    display_node(START);
    printf("\nenter the value for new node: ");
    scanf("%d",&info);
    START=append(START,info);
      display_node(START);
    return 0;
}
