#include <iostream>
#include <string.h>

using namespace std;

class BasicIfo {
	string Name;
	int Age;
	int ID;
	double Hight;
	double Weight;
};
/*
string Name;
int Age;
int ID;
double Hight;
double Weight;
*/
int main()
{
	cout<<"please enter your basic information here\n";
	cout<<"Name:";
	cin>>BasicIfo.Name;
	cout<<"\nAge:";
	cin>>Age;
	cout<<"\nID:";
	cin>>ID;
	cout<<"\nHight:";
	cin>>Hight;
	cout<<"\nWeight:";
	cin>>Weight;
	
	return 0;
}

