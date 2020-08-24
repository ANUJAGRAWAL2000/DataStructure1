#include<iostream>
using namespace std;
void Count(int A[],int N)
{
	int max,i,j;
	max=A[0];
	for(i=0;i<N;i++)
	{
		if(A[i]>max)
		max=A[i];
	}
	int B[max+1]={0};
	for(i=0;i<N;i++)
	{
		B[A[i]]=B[A[i]]+1;
	}
	j=0;
	for(i=0;i<max+1;i++)
	{
		while(B[i]>0)
		{
			A[j]=i;
			++j;
			B[i]=B[i]-1;
		}
	}
}
int main()
{
	int A[]={11,2,4,7,2,3,3,4,4,5,6,7,8};
	Count(A,13);
	for(int i=0;i<=12;i++)
	cout<<A[i]<<" ";
	cout<<'\n'; 
	return 0;
}
