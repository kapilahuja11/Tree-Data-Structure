#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* insert(struct node* q,int num)
{
	if(q==NULL)
	{
		q=(struct node*)malloc(sizeof(struct node));
		q->data=num;
		q->left=NULL;
		q->right=NULL;
		return q;
	}
	else
	{
		if(num < q->data)
		   q->left=insert(q->left,num);
		else
		   q->right=insert(q->right,num);
	}
}
struct node* del(struct node* q,int num)
{
	struct node *r,*temp;
	if(q==NULL)
	printf("tree was empty");
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
		return q;
	}
}
void inorder(struct node* q)
{
	if(q)
	{
		inorder(q->left);
		printf(" in: %d ",q->data);
		inorder(q->right);
	}
}
int main()
{
	struct node* p=NULL;
    p=insert(p,50);
  	insert(p,30);
  	insert(p,20);
  	insert(p,40);
  	insert(p,70);
  	insert(p,60);
  	insert(p,80);
  	//insert(p,6);
  	inorder(p);
    p=del(p,70);
    printf("\n");
    inorder(p);
    return  0;
}
