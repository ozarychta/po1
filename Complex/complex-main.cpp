#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
  Complex a(3,2),b(0,13),c;
  c = 10;
  cout << c <<endl;
  c = -a;
  cout << c <<endl;  
  c = a + b;
cout << c <<endl;
  c = c - Complex(10);
  cout << c <<endl;  
  c = 10 - a;
cout << c <<endl;
  c = a - 10;
cout << c << c <<endl;
  c +=b +=10;
  cout << c <<endl; 
Complex d (b);
  cout << d <<endl; 
c = a/2;
cout << c <<endl;
c = 2/a;
cout << c <<endl;
return 0;
}