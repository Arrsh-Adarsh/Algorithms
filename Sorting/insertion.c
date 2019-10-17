
#include<stdio.h>
#include<Conio.h>

void insertion(int [],int);

void main()
{
    int a[50],n,i;
    printf("Enter Total no. of Element : ");
    scanf("%d",&n);
    printf("\nEnter %d Elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion(a,n);
    printf("\n Sorted Array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    getch();
}

void insertion(int arr[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0&&temp<arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=temp;

        printf("\nArray after pass -%d is: ",i);
        for(j=0;j<size;j++)
            printf("%d\t",arr[j]);
    }

}
