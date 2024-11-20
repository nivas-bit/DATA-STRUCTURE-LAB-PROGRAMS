#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
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

NODE insert_beg(NODE first,int item){
NODE new;
new=getnode();
new->value=item;
new->next=NULL;
new->prev=NULL;
if(first==NULL)
    return new;
new->next=first;
first->prev=new;
return new;
}
NODE delete_val(NODE first,int key){
    NODE current=first;
    if(first==NULL){
        printf("LL is empty");

    }
while (current!=NULL && current->value!=key){
    current=current->next;

}
if (current->value==key){
    (current->prev)->next=current->next;
    (current->next)->prev=current->prev;
    free(current);
    return first;}
else{
        printf(" value not found");
        return NULL;
    }
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
        printf(" %d ",temp->value);
        temp=temp->next;
    }
}
void main(){

    NODE first=NULL;
    int choice,item,pos,value;
    while(1)
    {
        printf("\n Enter your choice\n 1.insert at beginning \n 2.delete at value\n 0.display\n");
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
                printf("Enter the value:");
                scanf("%d",&value);
                first=delete_val(first,value);
                break;
            }
        case 0:
            {
                display(first);
                break;
            }
        default:
            {
                printf("exiting\n");
                exit(0);
            }}}}
