#include<stdio.h>
#include<stdlib.h>
void insert(int q[],int *rear, int item,int qsize)
{
    if(*rear == qsize-1)
        printf("queue overflow\n");
    else
    {
        (*rear)++;
        q[*rear]=item;
    }
}

int delete(int q[],int *front,int *rear)
{
    if(*front>*rear)
    {
        printf("queue underflow\n");
        return -1;
    }
    else
    {
        return q[(*front)++];
    }
}

void display(int q[],int *front,int *rear)
{
    if(*front>*rear)
        printf("queue underflow\n");
    else
    {
        for(int i=*front;i<=*rear;i++)
            printf(" %d ",q[i]);
    }
}

void main()
{
    int qsize=3;
    int q[qsize];
    int choice,rear=-1,front=0,deleted_item,item;
    while(1)
    {
        printf("\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    printf("enter the item\n");
                    scanf("%d",&item);
                    insert(q,&rear,item,qsize);
                    break;
                }
            case 2:
                {
                    deleted_item=delete(q,&front,&rear);
                    if(deleted_item!=-1)
                        printf("%d",deleted_item);
                    break;
                }
            case 3:
                {
                    display(q,&front,&rear);
                    break;
                }
            default:
                {
                    printf("invalid choice");
                    exit(0);
                }
        }
    }
    printf("Name:lakshminivas h");
    printf("USN: 1BM23CS165");
}

