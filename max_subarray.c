//max subcrossing arrayy
#include<stdio.h>
#include<stdlib.h>
void max_sub_array(int a[],int low,int mid,int high)
{
  int left_sum=0,max_left,max_right,right_sum=0,cross_sum;
  int sum=0,i,j;
  if(high==low+1)//base case
  {
    printf(" %d ",a[0]);
    exit(0);
  }
  for(i=mid-1;i>=low;i--)
    {
    sum+=a[i];
  if(sum>left_sum)
    {
    left_sum=sum;
   max_left=i;}
   }
  sum=0;
  for(j=mid;j<high;j++)
  {
      sum+=a[j];
      if(sum>right_sum)
      {
        right_sum=sum;
      max_right=j;
      }
  }
  cross_sum=left_sum+right_sum;
  if(left_sum>right_sum && left_sum>=cross_sum)
  {
      printf("\nThe maximum subarray is\n");
      printf("\nThe maximum subarray is from let side\n");
      for(i=mid-1;i>=low;i--)
      {
          printf(" %d ",a[i]);
      }
    printf("\nThe left sum of the subarray is %d",left_sum);
       exit(0);
  }
  else if(right_sum>left_sum && right_sum>=cross_sum)
  {
      printf("\nThe maximum subarry is\n");
    printf("\nThe maximum subarray is from let side\n");
      for(i=mid;i<high;i++)
      {
          printf(" %d ",a[i]);
      }
   printf("\nThe right sum of the subarray is %d",right_sum);
      exit(0);
  }
  else{
  printf("\nThe max subarray is\n");
  for(i=max_left;i<=max_right;i++)
  {
      printf(" %d ",a[i]);
  }
  printf("\nThe left sum of the subarray is %d",left_sum);
  printf("\nThe right sum of the subarray is %d",right_sum);
  printf("\nThe sum of the maximum subarray is %d",left_sum+right_sum);
  exit(0);
  }
}
void main()
{
    int a[20],n,i,high,j,low,mid;
    low=0;
    printf("\nEnter elements in array\n");
    printf("\nEnter number of elements:- ");
    scanf("%d",&n);
    high=n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mid=n/2;
    max_sub_array(a,low,mid,high);
}
