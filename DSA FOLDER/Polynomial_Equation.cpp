#include<iostream>
#include<cmath>
using namespace std;
class Equation{
public:	//for accessing in other class;
	int coff;
	int pow;
};
class Poly{
	private:
	int N;
	class Equation *E;
	public:
	Poly(int N)
	{
		this->N=N;
		E=new Equation[this->N];
	}	
	~Poly()
	{
		delete []E;
	}
	void Create (class Poly *P);
	void Display(class Poly P);
};
void Poly::Create(class Poly *P)
{
for(int i=0;i<P->N;i++)
{	
cin>>P->E[i].coff;
cin>>P->E[i].pow;	
}	
}
void Poly::Display(class Poly P)
{	
int x;
for(int i=0;i<P.N;i++)
{	
cout<<P.E[i].coff;
cout<<"*";
cout<<P.E[i].pow;
cout<<'+';	
}	
}
int main()
{
    int N;
	cout<<"ENTER THE NO OF TERM IN POLYNOMIAL";
    cin>>N; 
	Poly P(N);
	P.Create(&P);
	P.Display(P);
	return 0;
	
}
