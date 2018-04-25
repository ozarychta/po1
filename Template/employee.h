#include <iostream>
#include <cstring>


using namespace std;

class Employee
{

public:
	string imie;
	string stanowisko;
	int wiek;
	
	Employee()
	{}
	
	Employee(string i,string s, int w)
	{
		imie=i;
		stanowisko=s;
		wiek=w;
	};

	friend ostream& operator<<(ostream& o, const Employee& e)
	{
		o<<e.imie<<" "<<e.stanowisko<<" "<<e.wiek<<endl;
		return o;
	};
};
