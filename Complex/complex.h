#ifndef __complex_H__
#define __complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
	double real, imaginary;
public:
	Complex ():real (0), imaginary (0){
  	};

	Complex (double number)
 	{
 	  real = number;
   	  imaginary = 0;
 	};

	Complex (double real, double imag)
  	{
   	  this->real = real;
   	  this->imaginary = imag;
 	};

	Complex & operator= (const Complex & s)
  	{
 	   real = s.real;
 	   imaginary = s.imaginary;
 	   return *this;
 	 };

 	 Complex operator- () const
 	 {
 	   return Complex(-real,-imaginary);
 	 };

 	 Complex & operator= (double co)
	  {
	    real = co;
 	   imaginary = 0;
  	  return *this;
 	 };

	  Complex operator+ (const Complex& co) const
 	 {
 	   Complex n;
 	   n.real = this->real + co.real;
   	 n.imaginary = this->imaginary + co.imaginary;
 	   return n;
 	 };


 	 Complex & operator+= (Complex co)
 	 {
  	  real += co.real;
  	  imaginary += co.imaginary;
 	   return *this;
 	 };

  	Complex & operator-= (Complex co)
  	{
  	  real -= co.real;
  	  imaginary -= co.imaginary;
 	   return *this;
 	 };


 	 friend Complex operator- (Complex, Complex);
	 friend ostream & operator << (ostream & s, const Complex & c)
  	{
  	  s << "(" << c.real << "," << c.imaginary << ")";
 	   return s;
 	 };
};

inline Complex
operator - (Complex s1, Complex s2)
{
  Complex n (s1);
  return n -= s2;
};

}

#endif
