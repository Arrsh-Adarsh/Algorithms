#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *link;
}*head=NULL;

void menu();
struct node* create();
int list_len();

void insert_beg();
void insert_end();
void insert_any();

void del_beg();
void del_end();
void del_any();

void sort_ace();
void sort_des();

void rev(struct node*);
void show();

int main()
{
    menu();
    getch();
    return 0;
}

void menu()
{
    int choice;
    printf(" \n       Menu\n");
    printf("  1. Insert At Begning\n");
    printf("  2. Insert At End\n");
    printf("  3. Insert At Any place\n");
    printf("  4. Delete From Begning\n");
    printf("  5. Delete From End\n");
    printf("  6. Delete From Any place\n");
    printf("  7. Sort In Acending Order\n");
    printf("  8. Sort In Decending Order\n");
    printf("  9. Reverse the list\n");
    printf("  10.Exit\n");
    printf("      Enter Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:  insert_beg();   break;
        case 2:  insert_end();   break;
        case 3:  insert_any();   break;
        case 4:  del_beg();      break;
        case 5:  del_end();      break;
        case 6:  del_any();      break;
        case 7:  sort_ace();     break;
        case 8:  sort_des();     break;
        case 9:  rev(head);show();     break;
        case 10:  exit(1);
        default:  printf(" Wrong Choice !!! \n");
    }
    menu();
}

struct node* create()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}

int list_len()
{
    int count=0;
    struct node *p= head;
    while(p)
    {
        p=p->link;
        count++;
    }
    return count;
}

void insert_beg()
{
    struct node *temp=create();
    temp->link=head;
    head=temp;
    show();
}

void insert_end()
{
    struct node *temp=create();
    if(head==NULL)
        head=temp;
    else
    {
        struct node *p=head;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
    show();
}

void insert_any()
{
    int n;
    printf("Enter position : ");
    scanf("%d",&n);
    if((n>list_len()+1)||n<1)
        printf("Exceed Size of List\n");
    else if(n==(list_len()+1))
        insert_end();
    else if(n==1)
        insert_beg();
    else
    {
        struct node *temp,*p=head;
        for(int i=1;i<n-1;i++)
            p=p->link;
        temp=create();
        temp->link=p->link;
        p->link=temp;
        show();
    }
}

void sort_ace()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
       struct node *p=temp;
       while(p!=NULL)
       {
            if((p->data)<(temp->data))
            {   int a;
                a=p->data;
                p->data=temp->data;
                temp->data=a;
            }
            p=p->link;
       }
       temp=temp->link;
    }
    show();
}

void sort_des()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
       struct node *p=temp;
       while(p!=NULL)
       {
            if((p->data)>(temp->data))
            {   int a;
                a=p->data;
                p->data=temp->data;
                temp->data=a;
            }
            p=p->link;
       }
       temp=temp->link;
    }
    show();
}

void del_beg()
{
    if(head==NULL)
        printf("\nUnderflow !!!!");
    else
    {
        struct node *p=head;
        head=head->link;
        printf("\nDeleted node is : %d\n",p->data);
        free(p);
    }
    show();
}

void del_end()
{
     if(head==NULL||(head->link==NULL))
        del_beg();
    else
    {
        struct node *t;
        struct node *temp=head;
        while(temp->link->link!=NULL)
            temp=temp->link;
        printf("Deleted node is : %d\n",temp->link->data);
        t=temp->link;
        temp->link=NULL;
        free(t);
        show();
    }
}

void del_any()
{
    int n;
    printf("Enter position : ");
    scanf("%d",&n);
    if((n>list_len())||n<1)
        printf("Exceed Size of List\n");
    else if(n==1)
        del_beg();
    else if(n==list_len())
        del_end();
    else
    {
        struct node *p=head,*temp;
        for(int i=1;i<n-1;i++)
            p=p->link;
        temp=p->link;
        p->link=temp->link;
        free(temp);
        show();
    }
}

void rev(struct node *temp)
{
    if(temp->link==NULL)
    {
         head=temp;
         return;
    }
    rev(temp->link);
    struct node *p=temp->link; // these 2 statement can be written as
    p->link=temp;              // temp->link->link=temp;
    temp->link=NULL;
}

void show()
{
    if(head==NULL)
        printf("\n List is Empty !!!\n");
    else
    {
        struct node *p=head;
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->link;
        }
    }
}
