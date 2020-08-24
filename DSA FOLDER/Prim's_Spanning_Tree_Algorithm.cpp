#include<iostream>
using namespace std;
#define I 32000
int A[][8]={{I,I,I,I,I,I,I,I},
            {I,I,25,I,I,I,5,I},
		    {I,25,I,12,I,I,I,10},
		    {I,I,12,I,8,I,I,I},
            {I,I,I,8,I,16,I,14},
		    {I,I,I,I,16,I,20,18},
		    {I,5,I,I,I,20,I,I},
            {I,I,10,I,14,18,I,I}  
           };
int Near[8]={I,I,I,I,I,I,I,I};
int B[2][6];        
int main()
{
	int i,j,min=I,U,V;
	for(i=1;i<8;i++)
	{
		for(j=i;j<8;j++)
		{
			if(A[i][j]<min)
			{
			min=A[i][j];
			U=i;
			V=j;
		    }
		}
	}
	B[0][0]=U;
	B[1][0]=V;
	Near[U]=Near[V]=0;
	for(j=1;j<8;j++)
	{
		if(Near[j]!=0)
		{
			if(A[j][U]<Near[j])
			Near[j]=U;
			if(A[j][V]<Near[j])
			Near[j]=V;
			if(A[j][V]==Near[j])
			Near[j]=V;
		}
	}
	for(i=1;i<6;i++)
	{
	min=I;
	for(j=1;j<8;j++)
	{
		if(Near[j]!=0)
		{
		if(A[j][Near[j]]<min)
		{
			min=A[j][Near[j]];
			U=j;
			V=Near[j];
		}
	    }
    }
    B[0][i]=U;
	B[1][i]=V;
	Near[U]=0;
	for(j=1;j<8;j++)
	{
		if(Near[j]!=0)
		{
			if(A[j][U]<A[j][Near[j]])
			Near[j]=U;
			//if(A[j][V]<Near[j])
			//Near[j]=A[j][V];
		}       
	}       
	}
	for(j=0;j<6;j++)
	{
		cout<<"("<<B[0][j]<<","<<B[1][j]<<endl;
	}
}
