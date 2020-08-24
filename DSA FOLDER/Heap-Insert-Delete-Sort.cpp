#include<iostream>
using namespace std;
void Insert(int A[],int N)
{
	int i,temp;
	i=N;
	while(i>1)
    {	
    if(A[i]>A[i/2])
    {
    temp=A[i];	
    A[i]=A[i/2];
    A[i/2]=temp;
    i=i/2;
	}
	else
	break;
    }
}
void Delete(int A[],int N)
{
	int k;
   	cout<<N<<"*";
	for(k=0;k<4;k++)
	cout<<A[k]<<" ";
	cout<<'\n';
    int i,j,x,temp;
    i=1;
	x=A[1];
	A[1]=A[N];
	j=2;
	while(j<N-1)
	{
	if(A[j]<A[j+1])
	j=j+1;
	if(A[i]<A[j])
	{
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;
		i=j;
		j=2*i;
	}
	else
	break;
	}	
	A[N]=x;
}
int main()
{
	int i,j;
	int A[]={0,50,60,35};
	for(i=2;i<=3;i++)
	Insert(A,i);
	for(i=0;i<4;i++)
	cout<<A[i]<<" ";
	for(i=3;i>=1;i--)
	{
	Delete(A,i);
	for(j=0;j<4;j++)
	cout<<A[j]<<" ";
	cout<<'\n';
	}
	return 0;
}
