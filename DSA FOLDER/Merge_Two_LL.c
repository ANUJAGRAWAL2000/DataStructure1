#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *Next;
}*first,*second,*third;
void Create(int A[],int n)
{
	int i;
	struct Node *T,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
    
	first->data=A[0];
	first->Next=NULL;
	T=first;
	for(i=1;i<n;i++)
	{
		last=(struct Node *)malloc(sizeof(struct Node));
		last->data=A[i];
		last->Next=NULL;
		T->Next=last;
		T=last;
	}
}
void Create2(int A[],int n)
{
	int i;
	struct Node *T,*last;
	second=(struct Node *)malloc(sizeof(struct Node));
    
	second->data=A[0];
	second->Next=NULL;
	T=second;
	for(i=1;i<n;i++)
	{
		last=(struct Node *)malloc(sizeof(struct Node));
		last->data=A[i];
		last->Next=NULL;
		T->Next=last;
		T=last;
	}
}
void Display (struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->Next;
	}
	printf("\n");
}
void Merge(struct Node *first,struct Node *second)
{
	struct Node *last2;
	third=(struct Node *)malloc(sizeof(struct Node));
	last2=(struct Node *)malloc(sizeof(struct Node));
	if(first->data < second->data)
	{
		third=first;
		last2=first;
		first=first->Next;
        last2->Next=NULL;
	}
	else
	{
		third=second;
		last2=second;
		second=second->Next;
		last2->Next=NULL;
		
	}
	while(first!=NULL && second!=NULL)
	{
	if(first->data<second->data)
	{
		last2->Next=first;
		last2=first;
		first=first->Next;
		last2->Next=NULL;
		
	}
    else
	{
		last2->Next=second;
		last2=second;
		second=second->Next;
		last2->Next=NULL;
		
	}
	}
	while(first)
	{
		//last2=(struct Node *)malloc(sizeof(struct Node));
		last2->Next=first;
		last2=first;
		last2->Next=NULL;
		first=first->Next;
	}
	while(second)
	{
		//last2=(struct Node *)malloc(sizeof(struct Node));
		last2->Next=second;
		last2=second;
		second=second->Next;
		last2->Next=NULL;
		
	}
/*if(first)
last2->Next=first;
if(second)
last2->Next=second;
*/}
int main()
{
	int A[]={20,40,50,60,70,75};
	int B[]={21,24,25,35,45,49};
	Create(A,6);
	Display(first);
	Create2(B,6);
	Display(second);
	Merge(first,second);
	Display(third);
	return 0;
}
