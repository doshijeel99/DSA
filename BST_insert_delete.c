#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
     int value;
     struct node* left;
     struct node* right;
};

struct node* root;

struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);
struct node* BinSearch(struct node* r, int data);
struct node* delete(struct node* r, int data);
struct node *find_min(struct node *r);

struct node* insert(struct node* r, int data)
{
     if(r==NULL)
     {
    r = (struct node*) malloc(sizeof(struct node));
    r->value = data;
    r->left = NULL;
    r->right = NULL;
     }
     else if(data < r->value){
    r->left = insert(r->left, data);
     }
     else {
    r->right = insert(r->right, data);
     }
     return r;

}

void inOrder(struct node* r)
{
     if(r!=NULL){
          inOrder(r->left);
          printf("%d ", r->value);
          inOrder(r->right);
     }
}

void preOrder(struct node* r)
{
     if(r!=NULL){
          printf("%d ", r->value);
          preOrder(r->left);
          preOrder(r->right);
     }
}

void postOrder(struct node* r)
{
     if(r!=NULL){
          postOrder(r->left);
          postOrder(r->right);
          printf("%d ", r->value);
     }
}

struct node* BinSearch(struct node* r, int data)
{
    if(r == NULL)
    {
        printf("Number doesn't exist");
    }
    else if(data == r->value)
    {
        printf("Item found");
        return 0;
    }
    else if(data<r->value)
        return BinSearch(r->left, data);
    else
        return BinSearch(r->right, data);
    return 0;
}
struct node *find_min(struct node *r)
{
    if(r == NULL)
        return 0;
    else if(r->left == NULL)
        return r;
    else
        return(find_min(r->left));
}

struct node* delete(struct node* r, int data)
{
    struct node *temp;
    if(r == NULL)
    {
        printf("Empty Tree");
        return r;
    }
    else if(data<r->value)
        r->left = delete(r->left, data);
    else if(data>r->value)
        r->right = delete(r->right, data);
    else if(r->left!=NULL && r->right!=NULL)
    {
        temp = find_min(r->right);
        r->value = temp->value;
        r->right = delete(r->right, r->value);
    }
    else
    {
        temp = r;
        if(r->left == NULL)
            r=r->right;
        else if(r->right == NULL)
            r=r->left;
        free(temp);
    }
    return r;
}

int height(struct node* r)
{
    int h_left;
    int h_right;
    if(r==NULL)
        return 0;
    h_left=height(r->left);
    h_right=height(r->right);
    if(h_left>h_right)
    {
        return 1+h_left;
    }
    return 1+h_right;
}
int count(struct node* r)
{
    if(r==NULL)
    return 0;
    return(1+count(r->left)+count(r->right));
}
void main()
{

     int i,n, v,choice;
     root = NULL;
     clrscr();
     do
     {
    printf("\n++++BINARY TREE FUNCTIONS++++");
    printf("\n1.Enter Node: ");
    printf("\n2.InOrder Traversal");
    printf("\n3.PreOrder Traversal");
    printf("\n4.PostOrder Traversal");
    printf("\n5.Search ");
    printf("\n6.Delete a Node");
    printf("\n7.Height of the tree");
    printf("\n8.Number of nodes in the tree");
    printf("\n9.EXIT");

    printf("\n\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter Data: ");
            scanf("%d", &v);
            root = insert(root, v);
            break;
        case 2: printf("Inorder Traversal: ");
            inOrder(root);
            printf("\n");
            printf("Minimum:%d",find_min(root)->value);
            break;
        case 3: printf("Preorder Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 4: printf("Postorder Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("\nEnter the data to be searched in the Binary Search Tree: ");
            scanf("%d",&v);
            root = BinSearch(root, v);
            break;
        case 6:
            printf("Enter the data to be deleted from the Binary Search Tree");
            scanf("%d",&v);
            root = delete(root, v);
            break;
        case 7:
            printf("\nHeight of the tree is %d",height(root));
            break;
        case 8:
            printf("\nTotal number of nodes in the tree are %d",count(root));
            break;
        case 9:
            printf("\n End Program");
            break;
        default:
            printf("\n Please Enter Choice from 1 to 8");

    }
     }while(choice !=9);
    getch();
}
