
#include<stdio.h>
int main()
{
    int frame1[20], frame2[20];
    int i,j=0,n,counter=0;
    printf(" Enter the size of frame1");
    scanf("%d",&n);
    printf("Enter the no. of bit for frame1 ");
    for(i=0;i<n;i++)
    {
                     scanf("%d",frame1[i]);
    }
    for(i=0;i<n;i++)
    {
                     if(frame1[i]==1)
                     {
                                     counter++;
                                     frame2[j]=frame1[i];
                                     j++;
                                     }
                     else
                     {
                         counter=0;
                         frame2[j]=frame1[i];
                         j++;
                         }
                     if(counter==5)
                     {
                         counter=0;
                         frame2[j]=0;
                         j++;
                         }
    }
printf("frame1: ");

     for(i=0;i<n;i++)
     {
                     printf("%d", frame1[i]);
                     }
     printf("\nframe2: ");
     for(j=0;j<n;j++)
     {
                     printf("%d", frame2[j]);
                     }
     return 0;       
                                                         
}
