#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST* NODE;

NODE create()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct BST));
    if(temp==NULL)
    {
        printf("node not created");
        return NULL;
    }
    printf("Enter the item");
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insert(NODE root,NODE temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    else
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}

void main()
{
    NODE root=create();
    NODE temp;
    int choice;
    while(1)
    {
        printf("\nEnter your choice\n 1.insert\n 2.Preorder\n 3.Inorder\n 4.Postorder\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                temp=create();
                insert(root,temp);
                break;
            }
            case 2:
            {
                preorder(root);
                break;
            }
            case 3:
            {
                inorder(root);
                break;
            }
            case 4:
            {
                postorder(root);
                break;
            }
            default:
                {
                    printf("invalid input");
                    exit(0);
                }
        }
    }

}
