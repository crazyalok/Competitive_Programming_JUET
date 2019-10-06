#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int INFO;
    struct Node *NEXT;
};
struct Node *create_node(int n)
{
    struct Node *START=NULL,*temp,*new_node;
    int i,info;
    if(n<=0)
        return NULL;
    START=(struct Node*)malloc(sizeof(struct Node));
    if (START==NULL)
        printf("memory can not be allocate");
    else
    {
         printf("enter value of node 1:");
         scanf("%d",&info);
         START->INFO=info;
         START->NEXT=START;
         temp=START;
        for(i=0;i<n-1;i++)
        {
            new_node=(struct Node*)malloc(sizeof(struct Node));
            if (new_node==NULL)
                printf("Memory can not be allocated.\n");
            else
            {
                printf("enter value of node %d: ",i+2);
                scanf("%d",&info);
                new_node->INFO=info;
                new_node->NEXT=START;
                temp->NEXT=new_node;
                temp=temp->NEXT;
            }
        }
    }
    return START;
}
void display_list(struct Node *START)
{
    struct Node *temp;
    if (START==NULL)
        printf("list is empty.\n");
    else
    {
        printf("linked list is:\n");
        printf("%u->",START);
        printf("%d->%u  ",START->INFO,START->NEXT);
        temp=START->NEXT;
        while(temp!=START)
        {
            printf("%d->%u  ",temp->INFO,temp->NEXT);
            temp=temp->NEXT;
        }
    }
}
int main()
{
    int n;
    printf("enter the no. of nodes you want: ");
    scanf("%d",&n);
    struct Node *START=create_node(n);
    display_list(START);
    return 0;
}

