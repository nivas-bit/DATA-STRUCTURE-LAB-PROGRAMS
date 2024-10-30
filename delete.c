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

NODE insert_end(NODE first,int item)
{
    NODE new_end,current;
    new_end=getnode();
    new_end->data=item;
    new_end->next=NULL;
    if(first==NULL)
        return new_end;
    current=first;
    while(current->next!=NULL)
        current=current->next;
    current->next=new_end;
    return first;
}

NODE insert_pos(NODE first,int item,int pos)
{
    int count;
    NODE new_node,prev,current;
    new_node=getnode();
    new_node->data=item;
    new_node->next=NULL;
    if(first==NULL && pos==1)
        return new_node;
    count=1;
    prev=NULL;
    current=first;
    while(count!=pos && current!=NULL)
    {
        prev=current;
        current=current->next;
        count++;
    }
    if(current==NULL)
    {
        printf("Invalid position\n");
        return first;
    }
    if(count==pos)
    {
        prev->next=new_node;
        new_node->next=current;
        return first;
    }
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

NODE delete_value(NODE first,int value_del)
{
    NODE prev,current;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
        return NULL;
    }
    prev=NULL;
    current=first;
    while(value_del!=current->data && current!=NULL)
    {
        prev=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("value not found\n");
        return first;
    }
    prev->next=current->next;
    free(current);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
        return NULL;
    }
    temp=first;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    NODE first=NULL;
    int choice,item,pos,value;
    while(1)
    {
        printf("Enter your choice\n 1.insert_beg\n 2.insert_end\n 3.insert_pos\n 4.delete_beg\n 5.delete_end\n 6.delete_value\n 7.display\n");
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
                printf("Enter the item:");
                scanf("%d",&item);
                first=insert_end(first,item);
                break;
            }
        case 3:
            {
                printf("Enter the item:");
                scanf("%d",&item);
                printf("Enter the pos:");
                scanf("%d",&pos);
                first=insert_pos(first,item,pos);
                break;
            }
        case 4:
            {
                first=delete_beg(first);
                break;
            }
        case 5:
            {
                first=delete_end(first);
                break;
            }
        case 6:
            {
                printf("Enter the value:");
                scanf("%d",&value);
                first=delete_value(first,value);
                break;
            }
        case 7:
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

