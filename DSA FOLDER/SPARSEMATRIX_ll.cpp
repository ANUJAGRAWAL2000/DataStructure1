#include<iostream>
using namespace std;
class sparse{
	public:
	int col;
	int data;
	sparse *first;
};
class Matrix{
    private:
    	sparse *A[5];
	public:
	Matrix(int M,int N)
	{
	    int i;
	   	for(i=0;i<M;i++)
	    {
	     A[i]=new sparse;
	     cin>>A[i]->col;
	     cin>>A[i]->data;
	     A[i]->first=NULL;
	    }
	   
	}
	void Display(int M,int N)
	{
	int i,j,X;
	X=0;
	sparse *P;
	for(i=0;i<M;i++)
	{
	P=new sparse;	
	P=A[i];
	for(j=0;j<N;j++)
	{
	if(P->col==j)
	cout<<P->data<<' ';
	else
	cout<<X<<' ';	
	}	
	cout<<'\n';
	}	
	}
};
int main()
{
int A,N;
cout<<"ENTER NO OF NON ZERO ELEMENT";
cin>>A>>N;
Matrix M(A,N);
M.Display(A,N);
}
