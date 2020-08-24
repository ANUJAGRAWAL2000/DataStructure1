#include<iostream>
using namespace std;
void Bubble_Sort(int A[],int N)
{
	int i,j,flag;
	for(i=0;i<N-1;i++)
	{
		flag=0;
		for(j=0;j<N-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
			swap(A[j],A[j+1]);
		    flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
void InsertionSort(int A[],int N)
{
	int i,j,X;
	for(i=1;i<N;i++)
	{
		j=i-1;
		X=A[i];
		while(j>-1&&A[j]>X)
		{
			A[j+1]=A[j];
			--j;
		}
		A[j+1]=X;
	}
}
void SelectionSort(int A[],int N)
{
	int i,j,k;
	for(i=0;i<N-1;i++)
	{
		j=i;
		k=i;
		for(j=i+1;j<N;j++)
		{
			if(A[k]>A[j])
			{
			k=j;
			}
		}
		swap(A[i],A[k]);
	}
}
int Partion(int A[],int l,int h)
{
	int pivot,i,j;
	pivot=A[l];
	i=l;
	j=h;
	do
	{
		do{i++;}while((pivot>=A[i])&&(i<h));
		do{j--;}while((pivot<=A[j])&&(j>l));
	    if(i<j)
		swap(A[j],A[i]);
	}while(i<j);
	swap(A[j],A[l]); 
	for(i=l;i<h;i++)
	cout<<A[i]<<" ";  
	cout<<'\n';            
	return j;
}                                       
void QuickSort(int A[],int l,int h)    
{
	int j;
	if(l<h)
	{
		j=Partion(A,l,h);
		//cout<<j<<'\n';
		QuickSort(A,l,j);
		QuickSort(A,j+1,h);
	}
}
void Merge(int A[],int B[],int N,int M)
{
	int i,j,k;
	k=0;
	i=0;
	j=0;
	int D[N+M];
	while((i<N)&&(j<M))
	{
		if(A[i]<B[j])
		{
			D[k++]=A[i++];
		}
		else
		{
			D[k++]=B[j++];
		}
	}
	while(i<N)
	D[k++]=A[i++];
	while(j<M)
	D[k++]=B[j++];
	for(i=0;i<N+M;i++)
	cout<<D[i]<<" ";
	cout<<'\n';
}
void ShellSort(int A[],int N)
{
	int G,i,j,temp;
	for(G=N/2;G>=1;G=G/2)
	{
		for(i=G;i<N;i++)
		{
			temp=A[i];
			j=i-G;
			while(A[j]>temp&&j>=0)
			{
				A[j+G]=A[j];
				j=j-G;
			}
			A[j+G]=temp;
		}
	}
}
int main()
{
	int i,A[]={8,7,9,6,5};
	Bubble_Sort(A,5);
	for(i=0;i<5;i++)
	cout<<A[i]<<" ";
	int B[5]={8,7,9,6,5};
	InsertionSort(B,5);
	for(i=0;i<5;i++)
	cout<<B[i]<<" ";
	int C[9]={8,1,4,3,2,7,9,6,5};
	SelectionSort(C,9);
	for(i=0;i<9;i++)
	cout<<C[i]<<" ";
	int D[]={11,2,3,4,6,5,10,8,9,13,7,6555};
	QuickSort(D,0,11);
	for(i=0;i<11;i++)
	cout<<D[i]<<" ";
	int E[]={2,5,6,8,9,10};
	int F[]={1,4,6,7,11,15,17};
	Merge(E,F,6,7);
	int G[9]={8,1,4,3,2,7,9,6,5};
	ShellSort(G,9);
	for(i=0;i<9;i++)
	cout<<G[i]<<" ";
	return 0;
}
