#include <iostream>
#include "matrix.h"

using namespace std;

int main(){

	rcMatrix m1("m3.txt");
	rcMatrix m2("m4.txt");
	
	cout << m1 << endl<< m2 << endl;
	
	cout << m2(1,0)<<endl;
	rcMatrix m3;
	m3=m1=m2;
    	m1+=m2;
	cout<< m1.getRc() << endl << m2.getRc() <<endl;

    cout << m1 << endl;
return 0;
}
