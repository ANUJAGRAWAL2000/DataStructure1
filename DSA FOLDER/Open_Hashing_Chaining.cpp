#include<iostream>
using namespace std;
class Node{
	public:
		int Data;
		Node *Next;
}*H[10];
int Hash(int Key)
{
	return Key%10;
}
void Sorted_Insert(Node **H,int Key)
{
    Node *T,*P=*H,*Q=NULL;
	T=new Node;
	T->Data=Key;
	T->Next=NULL;	
	if(*H==NULL)
	*H=T;
	else
	{
		while(P&&P->Data<Key)
		{
			Q=P;
			P=P->Next;
		}
		Q->Next=T;
		T->Next=P;
	}
}
Node* Search(Node *P,int Key)
{
	while(P!=NULL)
	{
		if(P->Data==Key)
		return P;
		P=P->Next;
	}
	return NULL;
}
void Insert(int Key)
{
	int I=Hash(Key);
	cout<<Key<<'\n';
	Sorted_Insert(&H[I],Key);
}
int main()
{
	int i;
	Node *T;
	for(i=0;i<10;i++)
	{
		H[i]=new Node;
		H[i]=NULL;
	}
	Insert(10);
	Insert(20);
	T=Search(H[Hash(10)],40);
	cout<<T->Data;
}
