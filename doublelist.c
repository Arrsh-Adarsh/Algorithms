#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head=NULL;

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
void search();

void rev();
void show();
void rev_print(struct node*);

void main()
{
    int choice;
    printf("  \n       Menu   \n");
    printf("  1. Insert At Begning\n");
    printf("  2. Insert At End\n");
    printf("  3. Insert At Any place\n");
    printf("  4. Delete From Begning\n");
    printf("  5. Delete From End\n");
    printf("  6. Delete From Any place\n");
    printf("  7. Sort In Acending Order\n");
    printf("  8. Sort In Decending Order\n");
    printf("  9. Reverse the list\n");
    printf("  10. Print List in Reverse Order\n");
    printf("  11. Search An Element in List\n");
    printf("  12. Exit\n");
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
        case 9:  rev();          break;
        case 10: rev_print(head);    break;
        case 11: search();       break;
        case 12:  exit(1);
        default:  printf(" Wrong Choice !!! \n");
    }
    main();
}

struct node* create()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("  Enter data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

int list_len()
{
    int count=0;
    struct node *temp=head;
    while(temp)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void insert_beg()
{
    if(head==NULL)
        head=create();
    else
    {   struct node *temp=create();
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
    show();
}

void insert_end()
{
    if(head==NULL)
        head=create();
    else
    {
        struct node *temp=create(),*p=head;
        while(p->next)
            p=p->next;
        temp->prev=p;
        p->next=temp;
    }
    show();
}

void insert_any()
{
    int n;
    printf("  Enter the position : ");
    scanf("%d",&n);
    if((n>(list_len()+1))||(n<1))
    {
         printf(" Invalid Position !!!\n ");
         insert_any();
    }
    else if(n==1)
        insert_beg();
    else if(n==list_len()+1)
        insert_end();
    else
    {
        struct node *temp=create(),*p=head;
        for(int i=1;i<n-1;i++)
            p=p->next;
        temp->next=p->next;
        p->next->prev=temp;
        temp->prev=p;
        p->next=temp;
        show();
    }
}

void del_beg()
{
    if(head==NULL)
        printf("  Underflow !!!\n ");
    else
    {
        struct node *temp=head;
        head=head->next;
        printf(" Deleted Node is : %d\n",temp->data);
        free(temp);
        if(head!=NULL)
            head->prev=NULL;
    }
    show();
}

void del_end()
{
    if(head==NULL||(head->next==NULL))
        del_beg();
    else
    {
        struct node *temp=head;
        while(temp->next)
            temp=temp->next;
        printf(" Deleted Node is : %d\n",temp->data);
        temp->prev->next=NULL;
        free(temp);
        show();
    }
}

void del_any()
{
    if(list_len()==0)
        printf(" List Is Empty\n");
    else
    {
        int n;
        printf(" Enter the position: ");
        scanf("%d",&n);
        if((n>list_len())||n<1)
        {
            printf(" Invalid Position !!!\n");
            del_any();
        }
        else if(n==list_len())
            del_end();
        else if(n==1)
            del_beg();
        else
        {
            struct node *temp=head;
            for(int i=1;i<n;i++)
                temp=temp->next;
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            printf(" Deleted Node is: %d\n",temp->data);
            free(temp);
            show();
        }
    }

}

void sort_ace()
{
    struct node *temp=head,*p;
    while(temp)
    {
        p=temp;
        while(p)
        {
            if(temp->data>p->data)
            {
                int a;
                a=temp->data;
                temp->data=p->data;
                p->data=a;
            }
            p=p->next;
        }
        temp=temp->next;
    }
    show();
}

void sort_des()
{
    struct node *temp=head,*p;
    while(temp)
    {
        p=temp;
        while(p)
        {
            if(temp->data<p->data)
            {
                int a;
                a=temp->data;
                temp->data=p->data;
                p->data=a;
            }
            p=p->next;
        }
        temp=temp->next;
    }
    show();
}

void rev()
{
    struct node *temp=head,*p=NULL,*t=NULL;
    while(temp)
    {
        t=temp;
        p=t->prev;
        t->prev=t->next;
        t->next=p;
        temp=temp->prev;
        head=t;
    }
    show();
}

void search()
{
    if(head==NULL)
        printf(" List is Empty !!!\n");
    else
    {
        struct node *temp=head;
        int n,count=0,flag=0;
        printf(" Enter Element to Search : ");
        scanf("%d",&n);
        while(temp)
        {
            count++;
            if(temp->data==n)
            {
                if(flag==0)
                    printf(" Element Found At: " );
                printf("%d\t",count);
                flag=1;
            }
            temp=temp->next;
        }
        if(flag==0)
            printf(" Element Not Found !!!\n");
    }
}

void show()
{
    if(head==NULL)
        printf("\n List is Empty !!!\n");
    else
    {
        struct node *temp=head;
        printf("\n List is: ");
        while(temp)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void rev_print(struct node *temp)
{
    if(head==NULL)
        printf("\n List is Empty !!!\n");
    else
    {
        if(temp==NULL)
        {
             printf("\n List is: ");
             return;
        }
        rev_print(temp->next);
        printf("%d\t",temp->data);
    }
}
