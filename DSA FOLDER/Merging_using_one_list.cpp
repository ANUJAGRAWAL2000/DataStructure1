#include<iostream>
using namespace std;
void Merge_By_one_Array(int A[],int l,int M,int h)
{
	int i,j,k;
	i=l;
	j=M+1;
	k=0;
	int B[h-l+1];
	while(i<=M&&j<=h)
	{
		if(A[i]<A[j])
		B[k++]=A[i++];
		else
		B[k++]=A[j++];
	}
	while(i<=M)
	B[k++]=A[i++];
	while(j<=h)
	B[k++]=A[j++];
	k=0;
	for(i=l;i<=h;i++)
	{
	//cout<<B[k]<<"";	
	A[i]=B[k];
	++k;
    }
//	for(i=l;i<=h;i++)
//	cout<<A[i]<<" ";
//	cout<<'\n';	
}
void Merge_sort_Iterative(int A[],int N)
{
	int i,l,M,h,j;
	for(i=2;i<=N;i=i*2)
    {
    	for(j=0;j+i-1<N;j=j+i)
    	{
    	l=j;
		h=j+i-1;
		M=(l+h)/2;
		Merge_By_one_Array(A,l,M,h);
		}
	}
	if(i/2<N)
	Merge_By_one_Array(A,0,i/2-1,N-1);
	for(i=0;i<N;i++)
	cout<<A[i]<<" ";
	cout<<'\n';
}
void Merge_Sort_Recursive(int A[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		Merge_Sort_Recursive(A,l,m);
		Merge_Sort_Recursive(A,m+1,h);
		Merge_By_one_Array(A,l,m,h);
	}
}
int main()
{
	int i;
	int A[]={2,5,3,6,7,5,9,11,1,10,8,9,10};
	Merge_sort_Iterative(A,12);
	for(i=0;i<12;i++)
	cout<<A[i]<<" ";
	cout<<'\n';
	int B[]={2,5,3,6,7,5,9,11,1,10,8,9,10};
	Merge_sort_Iterative(B,12);
	for(i=0;i<12;i++)
	cout<<A[i]<<" ";
	cout<<'\n';
}
