#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int max(int,int);
struct node* create();
void insert(struct node*,struct node*);
int search(struct node*, int);

void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

int isBst(struct node*,int);
void min_max();
int height(struct node*);

struct node* del(struct node*, int);
void main()
{
    int n,choice;

    printf("\n     Menu\n");
    printf(" 1. Insert\n");
    printf(" 2. search\n");
    printf(" 3. Preorder\n");
    printf(" 4. Inorder\n");
    printf(" 5. Postorder\n");
    printf(" 6. Find Minimum & Maximum Value in Tree\n");
    printf(" 7. Find Height of Tree\n");
    printf(" 8. Check For Binary search Tree\n");
    printf(" 9. TO Delete A node In Tree\n");
    printf(" 10. Exit\n");
    printf("  Enter Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert(root,create());        break;
        case 2: printf("Enter data to Search: ");
                scanf("%d",&n);
                n=search(root,n);
                if(n==1)
                    printf("Element Found \n");
                else
                    printf("Element Not Found \n");     break;
        case 3: preorder(root);                         break;
        case 4: inorder(root);                          break;
        case 5: postorder(root);                        break;
        case 6: min_max();                              break;
        case 7: n=height(root);
                printf(" Height of Tree is: %d\n",n);   break;
        case 8: n=isBst(root,INT_MIN);
                if(n==1)
                    printf(" This is Binary Search Tree\n");
                else
                    printf(" This is not a Binary Search Tree\n");  break;
        case 9: printf(" Enter the Value to Delete: ");
                scanf("%d",&n);
                root=del(root,n); break;
        case 10: exit(1);
        default: printf(" Wrong choice !!!\n");
    }
    main();
}

struct node* create()
{
   struct node *newnode= (struct node*)malloc(sizeof(struct node));
   printf(" Enter the Data: ");
   scanf("%d",&newnode->data);
   newnode->left=NULL;
   newnode->right=NULL;
}

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

void insert(struct node *temp,struct node *p)
{
    if(root==NULL)
    {
        root=p;
        return;
    }
    else if(p->data<=temp->data)
    {
        if(temp->left==NULL)
        {
            temp->left=p;
            return;
        }
         insert(temp->left,p);
    }
    else
    {
        if(temp->right==NULL)
        {
            temp->right=p;
            return;
        }
        insert(temp->right,p);
    }
}

int search(struct node* temp, int n)
{
    if(temp==NULL)
        return 0;
    else if(temp->data==n)
        return 1;
    else if(n<temp->data)
        search(temp->left,n);
    else
        search(temp->right,n);
}

void preorder(struct node* temp)
{
     if(temp==NULL)
        return;
     printf("%d\t",temp->data);
     preorder(temp->left);
     preorder(temp->right);

}

void inorder(struct node* temp)
{
     if(temp==NULL)
        return;
     inorder(temp->left);
     printf("%d\t",temp->data);
     inorder(temp->right);

}
void postorder(struct node* temp)
{
     if(temp==NULL)
        return;
     postorder(temp->left);
     postorder(temp->right);
     printf("%d\t",temp->data);
}

void min_max()
{
    if(root==NULL)
        printf(" Tree is Empty !!!\n");
    else
    {
        struct node* temp=root;
        while(temp->left)
            temp=temp->left;
        printf(" Minimum value is: %d\n",temp->data);
        temp=root;
        while(temp->right)
            temp=temp->right;
        printf(" Maximum Value is: %d\n",temp->data);

    }
}

int height(struct node* temp)
{
    if(temp==NULL)
        return -1;
    return max(height(temp->left),height(temp->right))+1;
}

int isBst(struct node* temp,int value)
{
     if(temp==NULL)
        return 1;
     else if(value>temp->data)
     {
         isBst(temp->left,value);
         value=temp->data;
         isBst(temp->right,value);
     }
     else
        return 0;

}

struct node* del(struct node *temp,int value)
{
    if(temp==NULL)
    {
        printf(" Node Not Found \n");
        return temp;
    }
    else if(value<temp->data)
       temp->left=del(temp->left,value);
    else if(value>temp->data)
        temp->right= del(temp->right,value);
    else
    {
        if(temp->left==NULL && temp->right==NULL)
        {
            free(temp);
            temp=NULL;
            printf(" Node is Deleted \n");
        }
        else if(temp->left==NULL)
        {
            struct node *p=temp;
            temp=temp->right;
            free(p);
            printf(" Node is Deleted \n");
        }
        else if(temp->right==NULL)
        {
            struct node *p=temp;
            temp=temp->left;
            free(p);
            printf(" Node is Deleted \n");
        }
        else
        {
            struct node *p=temp->right;
            while(p->left)
                p=p->left;
            temp->data=p->data;
            temp->right=del(temp->right,p->data);
        }
        return temp;
    }
}
