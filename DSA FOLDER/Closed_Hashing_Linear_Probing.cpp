#include<iostream>
using namespace std;
int Hash(int Key)
{
	return Key%10;
}
//Probe Function Tells About the Next Free Space..
//For Quadratic hashing Use i*i inPLace of i;
int Probe(int A[],int Index)
{
	int i;
	i=0;
	while(A[(Index+i)%10]!=NULL)
	++i;
	return Index+i;
}
void Insert(int A[],int Key)
{
	int I,X;
	I=Hash(Key);
	if(A[I]==0)
	A[I]=Key;
	else
	{
		X=Probe(A,I);
		A[X]=Key;
	}
}
int Search(int H[],int Key)
{
	int I,i;
	I=Hash(Key);
	i=0;
	while((H[(I+i)%10]!=Key)&&(H[(I+i)%10]!=NULL))
	++i;
	return (I+i)%10;
}
int main()
{
	int H[10]={0};
	Insert(H,10);
	Insert(H,15);
	Insert(H,36);
	Insert(H,11);
	Insert(H,20);
	for(int i=0;i<=9;i++)
	cout<<H[i]<<" ";
	cout<<Search(H,9);
	return 0;
}
