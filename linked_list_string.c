#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char INFO;
    struct Node *NEXT;
};
struct Node *create_node(int n)
{
    struct Node *START=NULL,*temp,*new_node;
    int i;
    char info;
    if(n<=0)
        return NULL;
    START=(struct Node*)malloc(sizeof(struct Node));
    if (START==NULL)
        printf("memory can not be allocate");
    else
    {
         printf("enter value of node 1:");
         scanf("%c",&info);
         fflush(stdin);
         START->INFO=info;
         START->NEXT=NULL;
         temp=START;
        for(i=0;i<n-1;i++)
        {
            new_node=(struct Node*)malloc(sizeof(struct Node));
            if (new_node==NULL)
                printf("Memory can not be allocated.\n");
            else
            {
                printf("enter value of node %d: ",i+2);
                scanf("%c",&info);
                 fflush(stdin);
                new_node->INFO=info;
                new_node->NEXT=NULL;
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
        temp=START;
        while(temp!=NULL)
        {
            printf("%c ",temp->INFO);
            temp=temp->NEXT;
        }
    }
}
struct Node *ll_string(struct Node *START)
{   int s;
    struct Node *temp1,*temp=START;
    while(temp!=NULL)
    {
        if(temp->INFO=='*' || temp->INFO=='/')
        {
            if(temp->NEXT->INFO=='*' || temp->NEXT->INFO=='/')
            {
                s=(temp->NEXT->NEXT->INFO);
                if(s>=97 && s<=122)
                        temp->NEXT->NEXT->INFO=(char)(s-32);
                temp1=temp->NEXT;
                temp->NEXT=temp1->NEXT;
                free(temp1);
            }
            temp->INFO=' ';
        }
        temp=temp->NEXT;
    }

    return START;
}
int main()
{
    int n;
    printf("enter the no. of nodes you want: ");
    scanf("%d",&n);
    fflush(stdin);
    struct Node *START=create_node(n);
    display_list(START);
    START=ll_string(START);
    display_list(START);
    return 0;
}

