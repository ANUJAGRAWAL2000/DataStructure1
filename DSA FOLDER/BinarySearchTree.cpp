#include<iostream>
using namespace std;
class BSET{
	public:
		int data;
		BSET *pre;
		BSET *last;
	};
class Node{
public:
	   BSET *data;
	   Node *Next;
};
class Stack{
	public:
		Node *P;
	public:
		Stack()
		{
		P=NULL;	
		}
		void Display(Node *P)
			{
				cout<<"1"<<'\n';
				while(P!=NULL)
				{
					cout<<P->data;
					P=P->Next;
					cout<<"\n";
				}
			}
	    void Push(BSET *X)
		{
		Node *T;
		T=new Node;
		if(T==NULL)
		cout<<"Stack OverFlow\n";
		else
		{
		T->data=X;
	    T->Next=P;
	    P=T;
		}
		}
		BSET* Pop()
		{
		BSET *X=NULL;	
		Node *N;	
	    if(P==NULL)
		return NULL;
		else
		{
		X=P->data;	
		N=P;
		P=P->Next;
		delete(N);	
		}		
		return X;
		}	
		BSET* StackTop()
		{
		if(P!=NULL)	
		return P->data;
		else
		return NULL;
		}	
};

class BST{
	public:
		BSET *Root,*P;
	public:
	    BST()
		{
		Root=NULL;
		P=NULL;	
		} 	
		void Create(int A[],int N)
		{
		Stack D;
		int i=0;
		BSET *Z,*T;
		//Z->data=NULL;	
		Root=new BSET;
		Root->data=A[i++];
		Root->last=Root->pre=NULL;
		P=Root;
		while(i<N)
		{
		if(P->data>A[i])
		{
		//BSET *T;
		T=new BSET;
		T->data=A[i++];
		T->last=T->pre=NULL;
		P->pre=T;
		//Stack D;
		D.Push(P);
		D.Display(D.P);
		P=T;	
		}	
		else
		{
		//Stack D;
		if(D.P!=NULL)
		Z=D.StackTop();	
		else if(Z==NULL)
		Z->data=75;
		if((Z->data>A[i])&&(P->data<A[i]))
		{
		//BSET *T;
		cout<<Z->data<<'\n';
		T=new BSET;
		T->data=A[i++];
		T->last=T->pre=NULL;
		P->last=T;
		P=T;
		D.Display(D.P);			
		}	
		else
		{
		//Stack D;
		D.Display(D.P);
		P=D.Pop();
		cout<<P<<'\n';
		}
		}
		}	
		}
	void PreOrder(BSET *W)
    {
    	if(W)
    	{
    	cout<<W->data;
    	PreOrder(W->pre);
    	PreOrder(W->last);
        } 
	}
	void InOrder(BSET *W)
    {
    	if(W)
    	{
    	InOrder(W->pre);
		cout<<W->data;
    	InOrder(W->last);
        } 
	}
	void PostOrder(BSET *W)
    {
    	if(W)
    	{
    	PostOrder(W->pre);
    	PostOrder(W->last);
    	cout<<W->data;
        } 
	}
};
int main()
{
	int A[]={30,20,10,15,25,40,50,45};
	BST B;
	B.Create(A,8);
	B.InOrder(B.Root);
	cout<<'\n';
	B.PostOrder(B.Root);
	cout<<'\n';
	B.PreOrder(B.Root);
	cout<<'\n';
	return 0;
}
