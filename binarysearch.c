#include<stdio.h>
#include<conio.h>
int search(int [],int);
void main()
{
   int a[10],item,index,i;
   printf("Enter 10 no.");
   for(i=0;i<10;i++)
    scanf("%d",&a[i]);
   printf("Enter no. to search");
   scanf("%d",&item);
   index=search(a,item);
    if(index==-1)
    printf("Item not found!!!!");
   else
   {
       printf("Item found at position %d",index+1);
   }
   getch();
}
int search(int arr[],int item)
{
    int start=0,end=9,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(item==arr[mid])
            return mid;
        else if(item>arr[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
