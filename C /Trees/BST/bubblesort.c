#include<stdio.h>
#include<stdlib.h>
main()
{
    int a[10],i,j,n,temp;
    printf("enter no oelements");
    scanf("%d",&n);
    printf("enterarray elemnts");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
              temp= a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
        }
        prinf("sorted list");
        for(i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
    }
}