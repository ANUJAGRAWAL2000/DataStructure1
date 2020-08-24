#include<iostream>
using namespace std;
class Node{
public:
	Node *pre;
	int data;
	Node *Next;
};
class LinkedList{
private:
	Node *first,*last;
public:	
	LinkedList(int A[],int n)
	{	
	int i;	
	first=NULL;
	//data=0;
	last=NULL;
	Node *t;
	first=new Node();
	last=new Node();
	first->data=A[0];
	first->pre=NULL;
	first->Next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		t=new Node;
		t->data=A[i];
		t->Next=NULL;
		t->pre=last;
		last->Next=t;
		last=t;
    }	
	}
	~LinkedList()
	{
	    Node *p=first;
    	while(p)
    	{
    		delete(p);
    		p=p->Next;
    	}	
	}
	void Display()
    {
    	Node *p=first;
    	while(p)
    	{
    		cout<<p->data;
    		p=p->Next;
    		cout<<'\n';
		}
	}
	void Insert(int index,int X)
	{
		int i;
		Node *R,*p;
		p=first;
		R=new Node;
		if(index==0)
		{
			if(first==NULL)
			{
            R->pre=NULL;				
			R->data=X;	
			R->Next=NULL;
			first=R;
			}
			else
			{
				 R->pre=NULL;				
			     R->data=X;	
			     first->pre=R;
			     R->Next=first;
			     first=R;
			}
		}
		else
		{
			for(i=0;i<index-1;i++)
			{
				p=p->Next;
			}				
			    R->data=X;	
			    R->Next=p->Next;
			    p->Next=R;
			    R->pre=p;
		}
	}
	void Delete(int A)
	{
	int i;
	Node *p,*q;
	q=new Node;
	q=NULL;
	p=first;	
	if(A==1)
    {
    	if(first==last)
    	{
    		delete(first);
    		delete(last);
    		first=NULL;
    		last=NULL;
		}
		else
		{
			first=first->Next;
			delete(p);
			first->pre=NULL;
		}
	}
	else
	{
		for(i=0;i<A-1;i++)
		{
		q=p;	
		p=p->Next;
		}
		q->Next=p->Next;
	    p->Next->pre=q;
	    delete(p);
	}
	}
};
int main()
{
	int A11[]={1,2};
	int index,X,D;
    LinkedList A(A11,2);
	A.Display();
	//cout<<"enter index  and value";
	//cin>>index>>X;
	//A.Insert(index,X);
	//A.Display();
	cout<<"enter index at which u want to delete";
	cin>>D;
	A.Delete(D);
	A.Display();
}
