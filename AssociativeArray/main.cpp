#include <iostream>
#include "assoctab.h"

using namespace std;

int main(){

AssocTab2 a1,a2;
a1["ala"]=1;
a1["Ala"]=2;
cout << a1["ala"] << " " << a1["ALA"]<< " " << a1["ula"]<< endl;
a2 = a1;

return 0;
}
