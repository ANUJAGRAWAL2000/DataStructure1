#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *Next;
}*first,*last;
void Create(int A[],int n)
{
	int i;
	struct Node *T;
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
void Display (struct Node *p)
{
	while(p->Next!=NULL)
	{
		printf("%d ",p->data);
		p=p->Next;
	}
}
int LinearSearch(struct Node *p,int key)
{
	struct Node *q;
	//q=(struct Node *)malloc(sizeof(struct Node));
	while(p->Next!=NULL)
	{
		if(key==p->data)
		{
			q->Next=p->Next;
			p->Next=first;
			first=p;
			return p->data;
		}
		q=p;
		p=p->Next;
	}
	return 0;
}
void Insert(struct Node *p,int N,int D)
{
	int i;
	for(i=0;i<D-1;i++)
	{
		p=p->Next;
	}
	struct Node *I;
	I=(struct Node *)malloc(sizeof(struct Node));
	I->data=N;
	I->Next=p->Next;
	p->Next=I;
}
int main()
{
	int A[]={2,3,4,5,6,7,};
	int X,Y,Z;
	Create(A,6);
	Display(first);
	printf("ENTER THE NUMBER U WANT TO CHECK IN THIS LINKED LIST?\n");
	scanf("%d",&X);
	printf("%d\n",LinearSearch(first,X));
	Display(first);
	printf("ENTER THE NUMBER U WANT TO INSERT IN THIS LINKED LIST AND ITS INDEX?\n");
	scanf("%d %d",&Y,&Z);
	Insert(first,Y,Z);
	Display(first);
	return 0;
}
