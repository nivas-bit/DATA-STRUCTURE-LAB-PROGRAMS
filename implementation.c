#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE getnode()
{
    NODE ptr;
    ptr=(NODE)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("node not created");
        return NULL;
    }
    return ptr;
}

NODE insert_beg(NODE first,int item)
{
    NODE new_node;
    new_node=getnode();
    new_node->data=item;
    new_node->next=NULL;
    if(first==NULL)
        return new_node;
    new_node->next=first;
    return new_node;
}

NODE delete_beg(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
        return NULL;
    }
    temp=first;
    first=first->next;
    free(temp);
    return first;
}

NODE delete_end(NODE first)
{
    NODE prev,last;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
        return NULL;
    }
    prev=NULL;
    last=first;
    while(last->next!=NULL)
    {
        prev=last;
        last=last->next;
    }
    prev->next=NULL;
    free(last);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
    }
    temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    NODE first=NULL;
    int choice,item,pos,value;
    while(1)
    {
        printf("\nEnter your choice\n 1.insert_beg\n 2.delete_beg\n 3.delete_end\n 4.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
               printf("Enter the item:");
               scanf("%d",&item);
               first=insert_beg(first,item);
               break;
            }
        case 2:
            {
                first=delete_beg(first);
                break;
            }
        case 3:
            {
                first=delete_end(first);
                break;
            }
        case 4:
            {
                display(first);
                break;
            }
        default:
            {
                printf("exiting\n");
                exit(0);
            }
        }
    }
}

