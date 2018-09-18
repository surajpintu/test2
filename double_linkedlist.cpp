#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int item;
    struct node *next;
    struct node *prev;
};
int count1(node *);
struct node *start=NULL;
void delete1(int index)
{
    node *k,*p,*t;
    int count2=1;
    t=start;
    if(index>count1(start)||index<=0)
    {
        cout<<"\nInvalid index";
    }
   else{
      while(count2!=index)
      {
          t=t->next;
          count2++;
      }
      count2++;
      if(count2==index)
      {
          p=t->next;
          k=p->next;
      }
      t->next=k;
      k->prev=p->prev;
      cout<<"\nThe item is succesfully deleteed from the linked list";
   }
}
int count1(node *t)
{
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    return c;
}
void insertAtfirst(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=NULL;
        n->prev=NULL;
        start=n;
    }
    else
    {
        n->prev=NULL;
        n->next=start;
        start=n;
    }
}
void printList(node *z)
{
    z=start;
    while(z!=NULL)
    {
        cout<<" "<<z->item;
        z=z->next;
    }
}
void insertatLast(int data)
{
    node *n=new node,*t;
    n->next=NULL;
    n->item=data;
    if(start==NULL)
    {
        start=n;
        n->prev=NULL;
        t=start;
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
        n->prev=t;

    }
}
void deleteByitem(int data)
{
    node *t,*k,*p;
    int l=0;
    t=start;

    while(t->item!=data)
    {
        p=t;
        t=t->next;
          if(t==NULL)
          {
            cout<<"\nItem is not found inside the list";
            break;
          }
    }
      if(t->item==data)
     {
        l++;
        k=t->next;
        p->next=k;
            k->prev=t->prev;

       }


}
void insertAfter(int index,int data)
{
    node *n=new node,*t,*p;
    t=start;
    int count1=0;
    while(count1!=index)
    {
        count1++;
        t=t->next;
    }
    if(count1==index)
    {
        p=t->next;
        t->next=n;
        n->prev=t;
        n->next=p;
        n->item=data;
        p->prev=n;
        cout<<"\nSucceesfully inserted";
    }
}
int menu()
{
    int choice;
    cout<<"\n1.Press 1 to insert element at last";
    cout<<"\n2.Press 2 to delete element by value";
    cout<<"\n3.Press 3 to delete element by index";
    cout<<"\n4.Press 4 to insert a value after a given index";
    cout<<"\n5.Press 5 to print list";
    cout<<"\nEnter your choice:- ";
    cin>> choice;
    return choice;
}
int main()
{
    int data,index,c;
while(1)
{
    switch(menu())
    {
    case 1:
        cout<<"\nEnter data to be inserted:- ";cin>>c;
        insertAtfirst(c);
        break;
    case 2:
        cout<<"\nEnter data to be deleted:- ";cin>>data;
        deleteByitem(data);
        break;
    case 3:
        cout<<"\nEnter index:- ";
        cin>>index;
        delete1(index);
        break;
    case 4:
        cout<<"\nEnter data to be inserted:- ";cin>>data;
         cout<<"\nEnter index:- ";
        cin>>index;
        break;
    case 5:
        printList(start);
        break;
    }
}
    return 0;
}
