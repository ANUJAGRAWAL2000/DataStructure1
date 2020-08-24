#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	int Balance;
	Node *lchild;
	Node *rchild;
};
class AVL{
	public:
		Node *Root,*P,*Q;
	public:
	    AVL()
		{
		Root=NULL;
		}	
		int Height(Node *U)
		{
			int H1,H2;
			H1=U&&U->lchild?U->lchild->Balance:0;
			H2=U&&U->rchild?U->rchild->Balance:0;
			return H1>H2?H1+1:H2+1;
		}
		int BF(Node *U)
		{
			int H1,H2;
			H1=U&&U->lchild?U->lchild->Balance:0;
			H2=U&&U->rchild?U->rchild->Balance:0;
			return H1-H2;
		}
	    Node* LLRotation(Node *P)
		{
			Node *Pl,*Plr;
			Pl=P->lchild;
			Plr=P->lchild->rchild;
			Pl->rchild=P;
			P->lchild=Plr;
			P->Balance=Height(P);
			Pl->Balance=Height(Pl);
			cout<<"LL"<<Pl->Balance<<" ";
			if(P==Root)
			Root=Pl;
			return Pl;
		}
		
		Node* RRRotation(Node *P)
		{
			Node *Pl,*Plr;
			Pl=P->rchild;
			Plr=P->rchild->lchild;
			P->rchild=Plr;
			Pl->lchild=P;
			P->Balance=Height(P);
			Pl->Balance=Height(Pl);
			cout<<"RR"<<Pl->Balance<<" ";
			if(P==Root)
			Root=Pl;
			return Plr;
		}
		
		
	    Node* LRRotation(Node *P)
		{
			Node *Pl,*Plr;
			Pl=P->lchild;         
			Plr=P->lchild->rchild;
			Pl->rchild=Plr->lchild;
			P->lchild=Plr->rchild;
			Plr->lchild=Pl;
			Plr->rchild=P;
			P->Balance=Height(P);
			Pl->Balance=Height(Pl);
			Plr->Balance=Height(Plr);
			cout<<"LR"<<Pl->Balance<<" ";
			if(P==Root)
			Root=Plr;
			return Plr;
		}	
		
		Node* RLRotation(Node *P)
		{
			Node *Pl,*Plr;
			Pl=P->rchild;         
			Plr=P->rchild->lchild;
			Pl->lchild=Plr->rchild;
			P->rchild=Plr->lchild;
			Plr->lchild=Pl;
			Plr->rchild=P;
			P->Balance=Height(P);
			Pl->Balance=Height(Pl);
			Plr->Balance=Height(Plr);
			cout<<"RL"<<Pl->Balance<<" ";
			if(P==Root)
			Root=Plr;
			return Pl;
		}	
		
		
		Node* Create(Node *P,int key)
		{
                if(P==NULL)
                {
                	Node *T;
			    	T=new Node;
			    	T->data=key;
			    	T->Balance=1;
			    	T->lchild=NULL;
			    	T->rchild=NULL;
			    	return T;
				}
				if(key>P->data)
			    {
			    P->rchild=Create(P->rchild,key);
				}
				if(key<P->data)
				{
				P->lchild=Create(P->lchild,key);	
				}
				P->Balance=Height(P);
				cout<<P->data<<" "<<P->Balance<<'\n';
				if((BF(P)==2)&&(BF(P->lchild)==1))
				{
					return LLRotation(P);
				}
				if((BF(P)==2)&&(BF(P->lchild)==-1))
				{
					return LRRotation(P);
				}
				if((BF(P)==-2)&&(BF(P->rchild)==-1))
				{
					return RRRotation(P);
				}
				if((BF(P)==-2)&&(BF(P->rchild)==1))
				{
					return RLRotation(P);
			 	}
				return P;
			}
	    void PreOrder(Node *P)
	    {
	    	if(P)
	    	{
	    		cout<<P->data<<" ";
	    		PreOrder(P->lchild);
	    		PreOrder(P->rchild);
		    }
		}
		Node* InPre(Node *T)
	    {
	    	while(T&&T->rchild!=NULL)
	    	T=T->rchild;
	    	return T;
		}
		Node* InSucc(Node *T)
		{
			while(T&&T->lchild!=NULL)
			T=T->lchild;
			return T;
		}
		Node* Delete(Node *P,int K)
		{
			if(P==NULL)
			{
			return NULL;
			}
			if((P->lchild==NULL)&&(P->rchild==NULL))
			{
				if(P==Root)
				Root=NULL;
				delete(P);
				return NULL;
			}
			if(K<P->data)
			P->lchild=Delete(P->lchild,K);
			else if(K>P->data)
			P->rchild=Delete(P->rchild,K);
			else 
			{
			if(Height(P->lchild)>Height(P->rchild))	
			{
			Q=InPre(P->lchild);
			P->data=Q->data;
			P->lchild=Delete(P->lchild,Q->data);	
			}
			else
			{
			Q=InSucc(P->rchild);
			P->data=Q->data;
			P->rchild=Delete(P->rchild,Q->data);		
			}
			}
			P->Balance=Height(P);
			if((BF(P)==2)&&(BF(P->lchild)==1))
			return LLRotation(P);
			if((BF(P)==2)&&(BF(P->lchild)==-1))
			return LRRotation(P);
			if((BF(P)==2)&&(BF(P->lchild)==0))
			return LLRotation(P);
			if((BF(P)==-2)&&(BF(P->lchild)==-1))
			return RRRotation(P);
			if((BF(P)==-2)&&(BF(P->lchild)==1))
			return RLRotation(P);
			if((BF(P)==2)&&(BF(P->lchild)==0))
			return RLRotation(P);
			return P;
		} 
		void InOrder(Node *W)
        {
    	if(W)
    	{
    	InOrder(W->lchild);
		cout<<W->data<<" ";
    	InOrder(W->rchild);
        } 
	    }
	    void PostOrder(Node *W)
        {
    	if(W)
    	{
    	PostOrder(W->lchild);
    	PostOrder(W->rchild);
    	cout<<W->data<<" ";
        } 
	    }
};
int main()
{
	AVL L;
	L.Root=L.Create(L.Root,30);
	L.Create(L.Root,20);
	L.Create(L.Root,24);
	L.Create(L.Root,22);
	//L.Create(L.Root,26);
	L.PreOrder(L.Root);
	cout<<'\n';
	L.InOrder(L.Root);
	cout<<'\n';
	L.PostOrder(L.Root);
	cout<<'\n';
	L.Delete(L.Root,20);
	L.PreOrder(L.Root);
	cout<<'\n';
	L.InOrder(L.Root);
	cout<<'\n';
	L.PostOrder(L.Root);
	return 0;
}
