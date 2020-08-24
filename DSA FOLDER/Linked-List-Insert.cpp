#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *Next;
};
class Create{
	public:
		Node *First;
		public:
			Create()
			{
			First=new Node;
			}
			void Insert()
			{
			int N,A;	
			cout<<"How Many Numbers Do U Want To Add"<<'\n';	
			cin>>N;
			while(N--)
			{
			cin>>A;
			Node *T;
			T=new Node;
			T->data=A;
			T->Next=NULL;
			if(First==NULL)
			First=T;
			else
			{
			First->Next=T;
			First=T;
			}
			}	
			}
};
int main()
{
	Create C;
	C.Insert();
}
