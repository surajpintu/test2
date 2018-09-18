#include<iostream>
using namespace std;
struct node
{
    int item;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *root=NULL;

node* max1(node *t)
{
    while(t->right!=NULL){
        t=t->right;}
        return t;
}
node* min1(node *t)
{
    while(t->left!=NULL)
    {
        t=t->left;
    }
return t;
}
node* createNode(int c)
{
    node *n=new node;
    n->item=c;
    n->left=NULL;
    n->right=NULL;
    return n;
}
node *insertData(node *ra,int data)
{
     if(ra==NULL)//insertion of first element inside tree
        return(createNode(data));//tail recusrion
    if(data<ra->item)
        ra->left=insertData(ra->left,data);
    else if(data>ra->item)
        ra->right=insertData(ra->right,data);
    return ra;
}
void inOrder(node *r)
{
    if(r!=NULL)
    {
        inOrder(r->left);
        cout<<" "<<r->item;
        inOrder(r->right);
    }
}
node* search1(node *r,int k)
{
while(r!=NULL && k!=r->item)
      if(k<r->item){
      r=r->left;
      }
else{
    r=r->right;
    }
return r;
}
void preorder(node *r)
{
    if(r!=NULL)
    {
        cout<<" "<<r->item;
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<" "<<r->item;

    }
}
node* tree_succesor(node *r)
{
    node *y;
    if(r->right!=NULL)
        return(min1(r->right));

}
node* tree_predecessor(node *r)
{
    node *y;
    if(r->left!=NULL)
        return(max1(r->left));
    y=r->parent;

}
int main()
{
    node *r2,*l;
    root=insertData(root,90);//first node ka addresss yahan pai hai
    insertData(root,800);
    insertData(root,89);
    insertData(root,700);
    insertData(root,978);
    insertData(root,213);
    insertData(root,69);
    cout<<"\nArrangement of the preorder loop inside it\n";
    inOrder(root);
    cout<<"\nArrangement of preorder number\n";
    preorder(root);
    cout<<"\nArrangement of the postorder numbers inside\n";
    postorder(root);
    search1(root,978);
   l=tree_succesor(root);
   cout<<"\nThe sucesoor of the root node is:-"<<l->item;
   l=tree_predecessor(root);
   cout<<"\nThe predecessor of the root node is:-"<<l->item;
   l=search1(root,89);
   tree_succesor(l);
    cout<<"\nThe sucessor of the  node is:-"<<l;


}

