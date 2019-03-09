#include<stdio.h>
#include<stdlib.h>
struct avl
{
	int height,data;
	struct avl *left;
	struct avl *right;
};
struct avl *leftrotation(struct avl *z);
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
   
   if(balance>1  && getbalance(q->left)>=0)
    return leftrotation(q);
   if(balance<-1 && getbalance(q->right)>=0)
    return rightrotation(q);
    if(balance>1 && getbalance(q->right)>=0)
      {
	     q->left=leftrotation(q->left);
	     return rightrotation(q);
	 }
	  if(balance<-1 && getbalance(q->left)>=0)
	  { 
	    q->right=rightrotation(q->right);
	 return leftrotation(q);
      }
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
	struct avl *y=z->right;
	struct avl *st=y->left;
	y->left=z;
     z->right=st;
	 z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;	
}
struct avl *leftrotation(struct avl *z)
{
	struct avl *y=z->left;
	struct avl *st=y->right;
	y->right=z;
	z->left=st;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
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
struct avl *del(struct avl *q,int num)
{
	struct avl *r,*temp;
	int balance;
	if(q==NULL)
	printf("tree is empty");
	else if(num<q->data)
	q->left=del(q->left,num);
	else if(num>q->data)
	q->right=del(q->right,num);
	else
	{
		if(q->left!=NULL && q->right!=NULL)
		{
			r=q;
			r=r->right;
			while(r->left!=NULL)
			 r=r->left;
			 
			  q->data=r->data;
			  q->right=del(q->right,q->data);
		}
		else
		{
			temp=q;
			if(q->left==NULL)
			 q=q->right;
			 else
			 q=q->left;
			 free(temp);
		}
	}
	return q;
	
	q->height=max(height(q->left),height(q->right))+1;
	balance=getbalance(q);
	 
	 if(balance>1  && getbalance(q->left)>=0)
    return leftrotation(q);
   if(balance<-1 && getbalance(q->right)>=0)
    return rightrotation(q);
    if(balance>1 && getbalance(q->right)>=0)
      {
	     q->left=leftrotation(q->left);
	     return rightrotation(q);
	 }
	  if(balance<-1 && getbalance(q->left)>=0)
	  { 
	    q->right=rightrotation(q->right);
	 return leftrotation(q);
      }
	   return q; 
}

int main()
{
	struct avl *p=NULL;
	p=avlinsertion(p,50);
	p=avlinsertion(p,30);
	p=avlinsertion(p,20);
    p=avlinsertion(p,40);
	p=avlinsertion(p,70);
	p=avlinsertion(p,60);
    p=avlinsertion(p,80);
   // avlinsertion(p,70);
	
	inorder(p);
	del(p,50);
	printf("\n");
	inorder(p);
}
