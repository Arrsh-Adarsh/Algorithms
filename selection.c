// Selection Sort

#include<stdio.h>
#include<Conio.h>

void selection(int [],int);

void main()
{
    int a[50],n,i;
    printf("Enter Total no. of Element : ");
    scanf("%d",&n);
    printf("\nEnter %d Elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    selection(a,n);
    printf("\n Sorted Array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    getch();
}

void selection(int array[],int size)
{
    int i,j,temp,min,p;
    for(i=0;i<size;i++)
    {
        min=array[i];
        p=i;
        for(j=i;j<size;j++)
         {
             if(min>array[j])
            {
                min=array[j];
                p=j;
            }
         }
        temp=array[p];
        array[p]=array[i];
        array[i]=temp;
        printf("\nArray after pass - %d is: ",i+1);
        for(j=0;j<size;j++)
            printf("%d\t",array[j]);
    }
}
