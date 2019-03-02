#include<stdio.h>
#include<stdlib.h>
struct avl
{
	int height,data;
	struct avl *left;
	struct avl *right;
};
struct avl *rightrotation(struct avl *z);
struct avl *avlinsertion(struct avl *q,int num)
{
	int balance;
	if(q==NULL)
	{
		q=(struct avl*)malloc(sizeof(struct avl));
		q->data=num;
		q->right=NULL;
		q->left=NULL;
		q->height=1;
		return q;
	}
	else if(num<q->data)
	q->left=avlinsertion(q->left,num);
	else
	 q->right=avlinsertion(q->right,num);
   
   q->height=max(height(q->left),height(q->right))+1;
   balance=getbalance(q);
   
   
   if(balance>1 && getbalance(q->left)>=0)
    return rightrotation(q);
   return q; 
}
int max(int a,int b)
{
	if(a>b)
	return a;
	return b;	
}
int height(struct avl *q)
{
	if(q==NULL)
	return 0;
	return q->height;
}
int getbalance(struct avl *q)
{
	if(q==NULL)
	return 0;
	return (height(q->left)-height(q->right));
}
struct avl *rightrotation(struct avl *z)
{
	struct avl *y=z->left;
	struct avl *st=y->right;
	y->right=z;
	z->left=st;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
struct avl *leftrotatation(struct avl *z)
{
	struct avl *y=z->right;
	struct avl *st=y->left;
	y->left=z;
     z->right=st;	
}
void inorder(struct avl* q)
{
	if(q)
	{
		inorder(q->left);
		printf(" inorder: %d->%d\n",q->data,q->height);
		inorder(q->right);
	}
}
int main()
{
	struct avl *p=NULL;
	p=avlinsertion(p,50);
	p=avlinsertion(p,30);
	p=avlinsertion(p,20);
	p=avlinsertion(p,80);
	p=avlinsertion(p,35);
	p=avlinsertion(p,10);
	inorder(p);
}
