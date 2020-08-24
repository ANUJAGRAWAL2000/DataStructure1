#include<iostream>
using namespace std;
class Queue{
public:	
	int data;
	Queue *Next;
};
class Create{
	private:
	Queue *front=NULL,*Rear=NULL;
	public:	
    void Enqueue(int X)
	{
		Queue *H;
		H=new Queue;
		if(H==NULL)
		cout<<"Queue is Full\n";
		else
		{
		H->data=X;
		H->Next=NULL;
		if(front==NULL)
		{
		front=new Queue;
		front=H;
		//cout<<front->data<<'\n';
		Rear=front;	
		}	
		else
		{
	    Rear->Next=H;
	    Rear=Rear->Next;
		}
		}
	}
	int Dequeue()
	{
		Queue *T;
		if(front==NULL)
		cout<<"Queue if Empty"<<'\n';
		else
		{
        T=new Queue;
		T->data=front->data;
		front=front->Next;
		}
		//cout<<T->data<<'\n';
		return T->data;
	}
//	Queue* isEmpty()
//	{
//		//if(front==Rear)
//		return front;
//	}
	void BFS(int A[][7],int start,int F)
	{
		int i=start,j;
		int N;
		int V[F]={0};
		cout<<i<<'\n';
		V[i]=1;
		Enqueue(i);
		while(!(front==NULL))
		{
			N=Dequeue();
			for(j=1;j<F;j++)
			{
				if(A[N][j]==1&&V[j]==0)
				{
					cout<<j<<'\n';
				    V[j]=1;
					Enqueue(j);
				}
			}
		}
	}
};
void DFS(int A[][7],int start,int N)
{
	static int V[7]={0};
	int j;
	if(V[start]==0)
	{
		V[start]=1;
		cout<<start<<'\n';
		for(j=1;j<N;j++)
		{
			if(A[start][j]==1&&V[j]==0)
			DFS(A,j,N);
		}
	}
}
int main()
{
	int G[][7]={  {0,0,0,0,0,0,0},
	              {0,0,1,1,0,0,0},
	              {0,1,0,0,1,0,0},
	              {0,1,0,0,1,0,0},
	              {0,0,1,1,0,1,1},
	              {0,0,0,0,1,0,0},
	              {0,0,0,0,1,0,0}};
	Create C;			    
	C.BFS(G,4,7);
	DFS(G,4,7);			  
}
