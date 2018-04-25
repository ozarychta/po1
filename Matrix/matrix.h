#ifndef __matrix_H__
#define __matrix_H__
#include <iostream>

using namespace std;

class rcMatrix{
	class Matrix;
	Matrix *matrix;
public:
	class Range{};
	class InequalSize{};
	class SizeZero{};
	class FilestreamOpeningError{};
	class Cref;
	rcMatrix( unsigned int row, unsigned int column);
	rcMatrix( const rcMatrix &m);
	rcMatrix( const char* fileName);
	rcMatrix( const double d);
	rcMatrix();
	~rcMatrix();
	
	rcMatrix& operator=(const rcMatrix &m);
	//friend rcMatrix operator= (const double n, rcMatrix &m);
	
	rcMatrix operator+(const rcMatrix &m)const;
	rcMatrix& operator+=(const rcMatrix &m);
	//friend rcMatrix operator+ (const double n, rcMatrix &m);	

	rcMatrix operator-(const rcMatrix &m)const;
	rcMatrix& operator-=(const rcMatrix &m);
	//friend rcMatrix operator* (const double n, rcMatrix &m);

	rcMatrix operator*(const rcMatrix &m)const;
	rcMatrix& operator*=(const rcMatrix &m);
	//friend rcMatrix operator* (const double n, Matrix &m);

	bool operator==(const rcMatrix &m);
	friend ostream& operator<<(ostream& s, const rcMatrix &m);

	void check(unsigned int row, unsigned int column) const;
	double read(unsigned int row, unsigned int column) const;
	void write(unsigned int row, unsigned int column, double element);

	double operator()(unsigned int row, unsigned int column) const;
	Cref operator()(unsigned int row, unsigned int column);

	int getRc();
	unsigned int index(const unsigned int row, const unsigned int column) const;



}; 
class rcMatrix::Matrix{

	friend class rcMatrix;
	double *data;
	int rows;
	int columns;
	int rc;
public:
	Matrix(	unsigned int row, unsigned int column);
	Matrix( const Matrix &m);
	Matrix( const char* fileName);
	Matrix( const double d);
	Matrix();
	
	~Matrix();

	Matrix* detach();
	void assign(const int rows,const int columns, double *ndata);

	Matrix& operator=(const Matrix &m);
	bool operator==(const Matrix &m);

	friend ostream& operator<<(ostream& s, const rcMatrix &m);
};

class rcMatrix::Cref{
	friend class rcMatrix;
	rcMatrix& m;
	int row, col;
	
	Cref(rcMatrix& mm, unsigned int rr,unsigned int cc);
public:
	operator double() const;
	rcMatrix::Cref& operator =(double d);
	rcMatrix::Cref& operator =(const Cref& ref);
};





#endif
