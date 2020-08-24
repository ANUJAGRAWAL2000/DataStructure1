#include<iostream>
#include<cmath>
using namespace std;
class Node{
public:	
	int data;
	Node *Next;
}*Bins[10];
int Count_Max_Digit(int A[],int N)               
{
	int i;
	int max,C;
	max=A[0];
	for(i=0;i<N;i++)
	{
		if(A[i]>max)
		max=A[i];
	}
	C=0;
	while(max>0)
	{
		max=max/10;
		++C;
	}
	return C;
}
void Inserted(Node **Bins,int Key) 
{
	//cout<<Key<<'\n';
	Node *T,*P=*Bins;
	T=new Node;
	T->data=Key;
	T->Next=NULL;
	if(*Bins==NULL)
	*Bins=T;
	else
	{
	while(P->Next!=NULL)
	P=P->Next;
	P->Next=T;
	}
}
int Shift(int A[],Node *P,int i)
{
	//static int i=0;
	A[i]=P->data;
	//cout<<"#"<<A[i]<<" ";
	++i;
	while(P->Next!=NULL)
	{
		P=P->Next;
		A[i]=P->data;
		//cout<<"#"<<A[i]<<" ";
		++i;
	}
	return i;
}
void Insert(int A[],int N)
{
	int Max,i,X,j,k,Y;
	Max=Count_Max_Digit(A,N);
	//cout<<Max<<" ";
	i=0;
	while(Max--)
	{
	for(j=0;j<=9;j++)
	{
	Bins[j]=new Node;
	Bins[j]=NULL;
	}	
	X=pow(10,i);
	//cout<<Max<<"is"<<X<<'\n';	
	for(j=0;j<N;j++)
	{
	Y=(A[j]/X)%10;
	Inserted(&Bins[Y],A[j]);  
	}
	k=0;	
	for(j=0;j<=9;j++)
	{
		if(Bins[j]!=NULL)
		{
			k=Shift(A,Bins[j],k); 
		}  
	} 
	++i;
	}
}
int main()
{
	int j;
	int A[]={124,342,234,564,546,11,23,33,21};            
	Insert(A,9);                                
	for(j=0;j<=8;j++)
	cout<<A[j]<<'\n';
	return 0;
}
