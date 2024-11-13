
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

NODE reverse(NODE first)
{
    NODE current,temp;
    current=NULL;
    if(first==NULL)
        return NULL;
    while(first!=NULL)
    {
        temp=first;
        first=first->next;
        temp->next=current;
        current=temp;
    }
    return current;
}

void sort(NODE first)
{
    NODE temp1,temp2;
    temp1=first;
    //temp2=first->next;
    while(temp1->next!=NULL)
    {
        temp2=temp1->next;
        while(temp2!=NULL)
        {
            if(temp1->data>=temp2->data)
            {
                int x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

NODE concatenate(NODE first1,NODE first2)
{
    NODE last1;
    if(first1==NULL && first2==NULL)
        return NULL;
    if(first1==NULL)
        return first2;
    if(first2==NULL)
        return first1;
    last1=first1;
    while(last1->next!=NULL)
        last1=last1->next;
    last1->next=first2;
    return first1;
}

void main()
{
    NODE first1=NULL;
    NODE first2=NULL;
    int choice,item,pos,value;
    while(1)
    {
        printf("\nEnter your choice\n 1.insert\n 2.reverse\n 3.sort\n 4.concatenate\n 5.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
               printf("Enter the item:");
               scanf("%d",&item);
               first1=insert_beg(first1,item);
               first2=insert_beg(first2,item);
               break;
            }
        case 2:
            {
                first1=reverse(first1);
                break;
            }
        case 3:
            {
                sort(first1);
                break;
            }
        case 4:
            {
                first1=concatenate(first1,first2);
                break;
            }
        case 5:
            {
                display(first1);
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


