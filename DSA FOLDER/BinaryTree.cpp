#include<iostream>
using namespace std;
class Node{
  public:
	Node *pre;
	Node *last;
	int data;
};
class Stack{
public:
Node *data;
Stack *Next;
};
class Queue{
public:	
	Node *data;
	Queue *Next;
};
class LinkedList{
public:
	Queue *front=NULL,*rear=NULL;
	Node *T,*P,*Root;
	Stack *first;
public:
	LinkedList()
	{
	front=NULL;
	rear=NULL;
	}
	void Enqueue(Node *X)
	{
	Queue *t;
	t=new Queue;
	if(t==NULL) 
	printf("Queue is Full\n");
	else
	{
	if(front==NULL)
	{
	t->data=X;
	t->Next=NULL;	
    front=t; 
	rear=front;	
	}	
	else
	{
	t->data=X;
	t->Next=NULL;
	rear->Next=t;
	rear=rear->Next;	
	}
	}	
	}
	Node* Dequeue()
	{
	Node *z=NULL;
	Queue *t;
	if(front==NULL)
	printf("Queue is Empty\n");
	else
	{
	t=front;
	front=front->Next;
	z=t->data;
	delete(t);
	}	
	return z;
	}
	void Display()
	{
		Queue *p;
		p=front;
		while(p!=NULL)
		{
		cout<<p->data<<'\n';
		p=p->Next;	
		}
	}
	int isEmpty()
	{
		if(front==NULL)
		return 1;
		else
		return 0;
	}
	int isEmpty1()
	{
		if(first==NULL)
		return 1;
		else
		return 0;
	}
    void BinaryTree()
    {
    	int X;
    	//Node *D;
    	cout<<"Enter Root Value";
    	cin>>X;
    	Root=new Node;
    	Root->data=X;
    	Root->last=NULL;
    	Root->pre=NULL;
    	P=Root;
    	cout<<P->data<<'\n';
    	Enqueue(Root);
    	while(!isEmpty())
    	{
    		P=Dequeue();
    		cout<<"Enter Left Child of"<<P->data;
    		cin>>X;
    		if(X!=-1)
    		{
    		T=new Node;
			T->data=X;
			T->last=NULL;
			T->pre=NULL;
			P->pre=T;
			Enqueue(T);	
			}  
        	cout<<"Enter Right Child"<<P->data;
    		cin>>X;
    		if(X!=-1)
    		{
    		T=new Node;
			T->data=X;
			T->last=NULL;
			T->pre=NULL;
			P->last=T;
			//P=P->last;
			//cout<<P->data<<'\n';
			Enqueue(T);	
			}
		}
    	
    }
    void PreOrder(Node *W)
    {
    	if(W)
    	{
    	cout<<W->data;
    	PreOrder(W->pre);
    	PreOrder(W->last);
        } 
	}
	void InOrder(Node *W)
    {
    	if(W)
    	{
    	InOrder(W->pre);
		cout<<W->data;
    	InOrder(W->last);
        } 
	}
	void PostOrder(Node *W)
    {
    	if(W)
    	{
    	PostOrder(W->pre);
    	PostOrder(W->last);
    	cout<<W->data;
        } 
	}
	void Push(Node *X)
			{
				Stack *N;
				N=new Stack;
				if(N==NULL)
				cout<<"Stack Overflow";
				else
				{
				N->data=X;
				N->Next=first;
				first=N;
				}
			}
			Node* Pop()
			{
				Node *X=NULL;
				Stack *N;
				if(first==NULL)
				cout<<"Stack is empty";
				else
				{
				X=first->data;
				N=first;
				first=first->Next;	
				delete(N);
				}
				return X;
			}
			void IterativePO(Node *T)
			{
				int V=0;
				Node *temp;
				while((T!=NULL)||(!isEmpty1()))
				{
					if(T!=NULL) 
					{
					Push(T);
					T=T->pre;
					V=0;	
					}
					else
					{
					temp=Pop();
					if(V==0)
					{
					Push(temp);
					T=temp->last;
					if(T==NULL) 
					V=-1;
					else
					V=0;
					}  
					else
					{
					cout<<temp->data;
					T=NULL;
					V=0;	
					}
					}
				}
			}
};
int main()
{
	LinkedList L;
	L.BinaryTree();
	L.PreOrder(L.Root);
	cout<<'\n';
	L.InOrder(L.Root);
	cout<<'\n';
	L.PostOrder(L.Root);
	cout<<'\n';
	L.IterativePO(L.Root);
	cout<<'\n';
	return 0;
}

