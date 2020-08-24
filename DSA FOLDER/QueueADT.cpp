#include<stdio.h>
using namespace std;
class Queue{
private:
	int size;
	int front;
	int rear;
	int *Q;
	public:
	Queue()
	{
		printf("Enter the Size Of Array");
		scanf("%d",&size);
		front=-1;
		rear=-1;
		Q=new int[size];
	}
	~Queue()
	{
	delete[]Q;	
	}
	void Enqueue(int X)
	{
		if(rear==size-1)
		printf("Queue is Full\n");
		else
		{
			rear++;
			Q[rear]=X;
		}
	}
	int Dequeue()
	{
		int X=-1;
		if(front==rear)
		printf("Queue if Empty\n");
		else
		{
		front++;	
		X=Q[front]; 
			
		}
		return X;
	}
	void Display()
	{
		int i;
		for(i=front+1;i<=rear;i++)
		printf("%d\n",Q[i]);
	}
};

int main()
{
int Z,Y;
Queue Q;
Q.Enqueue(10);
Q.Enqueue(20);	
Q.Display();	
Z=Q.Dequeue();
printf("DELETE NO IS %d\n",Z);
Q.Display();	
printf("ENETR THE NO YOU WANT TO ADD\n");
scanf("%d",&Y);
Q.Enqueue(Y);
Q.Display();	
return 0;
}
