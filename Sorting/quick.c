#include<stdio.h>
#include<conio.h>

void quick(int[], int , int);

void main()
{
    int a[50],n,i;
    printf("Enter Total no. of Element : ");
    scanf("%d",&n);
    printf("\nEnter %d Elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick(a,0,n-1);
    printf("\n Sorted Array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    getch();
}

void quick(int a[],int start,int end)
{
    int i,j,temp,pivot;
    if(start<end)
    {
       pivot=start;
       i=start;
       j=end;
       while(i<j)
       {
            while(a[i]<=a[pivot]&&i<end)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
       }
       temp=a[j];
       a[j]=a[pivot];
       a[pivot]=temp;
       quick(a,start,j-1);
       quick(a,j+1,end);
    }
}
