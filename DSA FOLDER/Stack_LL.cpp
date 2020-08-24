#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *Next;
}*first,*last;
class Stack{
	    private:
		Node *p; 
		public:
			Stack()
			{
			 	first=new Node;
				cin>>first->data;	 
				first->Next=NULL;
				last=first;
				while(last->data!=0)
				{
			 	p=new Node;
			 	cin>>p->data;
			 	p->Next=NULL;
			 	last->Next=p;
			 	last=p;
			    }
			}
			void Display(Node *P)
			{
				while(P->data!=0)
				{
					cout<<P->data;
					P=P->Next;
					cout<<"\n";
				}
			}
			void Push(int X)
			{
				Node *N;
				//p=first;
				N=new Node;
				if(N==NULL)
				cout<<"Stack Overflow";
				else
				{
				N->data=X;
				N->Next=first;
				first=N;
				}
			}
			int Pop()
			{
				int X=-1;
				Node *N;
				//N=new Node;
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
			int Peek(int X)
			{
				int i,Y=-1;
				Node *p=first;
				for(i=0;i<X-1;i++)
				{
				p=p->Next;
				}
				if(p!=NULL)
			    return p->data;
				else 
				return Y;
			}
};
int main()
{
	int N,Pos,Y,X;
	cout<<"ENTER ELEMENTS TO CREATE LINKED LIST";
	Stack S;
	S.Display(first);
	cout<<'\n'<<"ENETR VALUE U WANT TO INSERT"<<'\n';
	cin>>N;
	S.Push(N);
	S.Push(20);
	S.Push(1001);
	S.Display(first);
	Pos=S.Pop();
	cout<<"Deleted value"<<'\n'<<Pos;
	cout<<"ENTER THE pos U WANT TO SEARCH"<<'\n';
	cin>>X;
	Y=S.Peek(X);
	cout<<Y<<'\n';
	return 0;
}
