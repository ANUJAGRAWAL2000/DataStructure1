#include<stdio.h>
#include<stdlib.h>
struct Matrix{
int i;
int j;
int k;
};
struct Sparse{
int m;
int n;
int p;
struct Matrix *E;
};
void Create(struct Sparse *S)
{
	int i;
	printf("ENTER NO OF NON-ZERO ELEMENT IN MATRIX");
	scanf("%d %d %d",&S->m,&S->n,&S->p);
	S->E=(struct Matrix *)malloc(S->p*sizeof(struct Matrix));
	for(i=0;i<S->p;i++)
	{
		scanf("%d %d %d",&S->E[i].i,&S->E[i].j,&S->E[i].k);
	}
}
void Display(struct Sparse S)
{
	int i,j,k;
	k=0;
	for(i=0;i<S.m;i++)
	{
	for(j=0;j<S.n;j++)
	{
		if(i==S.E[k].i  &&  j==S.E[k].j)
		printf("%d ",S.E[k++].k);
		else
		printf("0 ");
    } 
    printf("\n");
	}
}
void Add(struct Sparse S,struct Sparse S1,struct Sparse *S2)
{
	S2->m=S.m;
	S2->n=S.n;
	int i,j,k;
	i=0;
	j=0;
	k=0;
	S2->E=(struct Matrix *)malloc((S1.p+S.p)*sizeof(struct Matrix));
  	while(i<S.p&&j<S1.p)
  	{
	 	if(S.E[i].i<S1.E[j].i)
		{
			S2->E[k++]=S.E[i++];
			//S2->E[k++].j=S.E[i++].j;
			//S2->E[k++].k=S.E[i++].k;
		}
		else if(S.E[i].i>S1.E[j].i)
		{
			S2->E[k++]=S1.E[j++];
			//S2->E[k++].j=S1.E[j++].j;
			//S2->E[k++].k=S1.E[j++].k;
		}
		else if((S.E[i].j<S1.E[j].j))
		{
			S2->E[k++]=S.E[i++];
			//S2->E[k++].j=S.E[i++].j;
			//S2->E[k++].k=S.E[i++].k;
		}
		else if(S.E[i].j>S1.E[j].j)
		{
			S2->E[k++]=S1.E[j++];
			//S2->E[k++].j=S1.E[j++].j;
			//S2->E[k++].k=S1.E[j++].k;

		}
		else if((S.E[i].j==S1.E[j].j)&&(S.E[i].i==S1.E[j].i))
		{
			S2->E[k]=S1.E[j++];
			//S2->E[k++].j=S1.E[j++].j;
			S2->E[k].k=S2->E[k].k+S.E[i++].k;
			++k;
		}              
	}                                                          
	for(;i<S.p;i++)
	S2->E[k++]=S.E[i++];
	for(;j<S1.p;j++)
	S2->E[k++]=S1.E[j++];
	S2->p=k;
}
int main()
{
	struct Sparse S;
	Create(&S);
	Display(S);
	struct Sparse S1;
	Create(&S1);
	Display(S1);
	struct Sparse S2;
	Add(S,S1,&S2);
	Display(S2);
	return 0;
}
