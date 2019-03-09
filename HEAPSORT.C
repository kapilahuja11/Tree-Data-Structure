#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void heapify(int i,int length);
int a[50];
void build_max_heap(int length)
{
	int i;
	for(i=length/2;i>0;i--)
	{
		heapify(i,length);
	}

}
void heapify(int i,int length)
{ 
	int l,r,largest,s,size;
	l=2*i;
	r=(2*i)+1;
	size=length;
	if(l<=size && a[l]>a[i])
	{
		largest=l;
	}
	else
	largest=i;
	
	if(r<=size && a[r]>a[largest])
	largest=r;
	
	if(largest!=i)
	{
		s=a[i];
		a[i]=a[largest];
		a[largest]=s;
		heapify(largest,length);	
	}
}

void swap(int b,int i)
{
	int temp;
	temp=a[1];
	a[1]=b;
	a[i]=temp;
}
void mergesort(int length)
{
	int i,reduce=length;
	for(i=length;i>=1;i--)
	{
		swap(a[i],i);
		reduce--;
			build_max_heap(reduce);
	}
	
}

int main()
{
	int i,length;
 printf("enter the length/n");
 scanf("%d",&length);
printf("Enter the numbers");
for(i=1;i<=length;i++)
scanf("%d",&a[i]);
	build_max_heap(length);
	
	for(i=1;i<=length;i++)
	printf("%d ",a[i]);
	
		mergesort(length);
		printf("\n");
	for(i=1;i<=length;i++)
	{
	printf("%d ",a[i]);
   }
}

