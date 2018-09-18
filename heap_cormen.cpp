//program to create a heap
#include<conio.h>
#include<iostream>
using namespace std;
int heap_size;
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return (2*i+1);
}

void MAX_HEAPIFY(int s[],int index)
{
    int l,r,largest,t;
    l=2*index;
    r=2*index+1;
    if (l<=heap_size && s[l]>s[index])
        largest=l;
    else
        largest=index;
    if(r<=heap_size&& s[r]>s[largest])
        largest=r;
    if(largest!=index)
    {
        t=s[index];
        s[index]=s[largest];
        s[largest]=t;
        MAX_HEAPIFY(s,largest);
    }
}
void BUILD_MAX_HEAP(int D[],int k)
{
    for(int i=(k/2);i>=1;i--)
    {
        MAX_HEAPIFY(D,i);
    }

}
void HEAPSORT(int B[])
{
    int l,i;
  BUILD_MAX_HEAP(B,heap_size);
   for ( i=heap_size;i>=2;i--){
    l=B[i];
    B[i]=B[1];
    B[1]=l;
   heap_size=heap_size-1;
   MAX_HEAPIFY(B,1);}
}
int main()
{
    int a[30],i,n;
    cout<<"\nEnter all the elements of the array";
    cout<<"\nEnter the number of elements in the array:- ";
    cin>>heap_size;
    n=heap_size;
    for(i=1;i<=heap_size;i++){
        cout<<"\nEnter element"<<i<<":";
        cin>>a[i];}
            HEAPSORT(a);
            cout<<"finally the sorted array\n";
            for(i=1;i<=n;i++)
            {
                cout<<" "<<a[i];
            }
}
