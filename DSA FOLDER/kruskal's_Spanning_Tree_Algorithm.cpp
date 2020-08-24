#include<iostream>
using namespace std;
#define Max INT_MAX
int E[][9]={{1,1,2,2,3,4,4,5,5},
            {2,6,3,7,4,5,7,6,7},
			{25,5,12,10,8,16,14,20,18} 
            };
int I[9]={0};
int T[2][6];
int S[8]={-1,-1,-1,-1,-1,-1,-1,-1};
void Union(int A,int B)
{
    if(S[A]<S[B])
    {
     	S[A]=S[A]+S[B];
     	S[B]=A;
	}
	else
    {
	 	S[B]=S[A]+S[B];
	 	S[A]=B;
    }
}
int Find(int A)
{
    while(S[A]>0)
	{
	A=S[A];	
	}	
	
	return A;
}  
int main()
{
	int i=0,j,k,e,N,min,U,V;
	N=7;
	e=9;
	while(i<N-1)
	{
		min=Max;
		for(j=0;j<e;j++)
		{
			if(I[j]==0)
			{
				if(E[2][j]<min)
				{
					min=E[2][j];
					k=j;
					U=E[0][j];
					V=E[1][j];
				}
			}
		}
		cout<<min<<'\n';
		if(Find(U)!=Find(V))
		{
			T[0][i]=U;
			T[1][i]=V;
			Union(Find(U),Find(V));
			i++;
		}
		I[k]=1;
	}
	for(i=0;i<N-1;i++)
	{
		cout<<T[0][i]<<" "<<T[1][i]<<'\n';
	}
	return 0;
}                      
