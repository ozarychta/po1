#include <iostream>
#include <fstream>
#include <new>
#include "matrix.h"
//rule of three
//size nxm
//min 3 exceptions

using namespace std;

//Matrix
rcMatrix::Matrix::Matrix( unsigned int row, unsigned int column){
cout << "\nkonstruktor matrixSize\n";
	if(row>0 && column>0){
		
		this->rows = row;
		this->columns = column;
		try{
		this->data = new double	[rows*columns];
		} 
		catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
		for(int i=0; i < rows*columns; i++){
			this->data[i]=0;	
		}
		rc=1;
	}
	else throw SizeZero();
}

rcMatrix::Matrix::Matrix(const double d){
	this->rows = 1;
	this->columns=1;
		try{
		this->data = new double	[1];
		} 
		catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
	rc=1;
	this->data[0]=d;
}

rcMatrix::Matrix::Matrix(){
	this->rows = 1;
	this->columns=1;
		try{
		this->data = new double	[1];
		} 
		catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
	rc=1;
	this->data[0]=0;
}

rcMatrix::Matrix::Matrix(const char* fileName){
	cout << "\nkonstruktor fileName\n";
	ifstream s(fileName);
	if(!s){ throw FilestreamOpeningError(); }
	s >> rows;
	s >> columns;
	try{
	data = new double[rows*columns];
	} 
	catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
	for(int i=0; i < this->rows*columns; i++){
		s >> this->data[i];	
	}
	rc=1;
	s.close();
}
	
rcMatrix::Matrix::Matrix(const Matrix &m){
	cout << "\nkonstruktor kopiujacy\n";
	this->rows=m.rows;
	this->columns=m.columns;
	try{
	this->data = new double	[rows*columns];
	} catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
	for(int i=0; i<rows*columns; i++){
		this->data[i]=m.data[i];
	}
	rc=1;
}

rcMatrix::Matrix::~Matrix(){
	delete[] this->data;
}


rcMatrix::Matrix* rcMatrix::Matrix::detach(){
	if(rc==1) return this;
	Matrix* m = new Matrix(*this);
	rc--;
	return m; 
}

void rcMatrix::Matrix::assign(const int nrows ,const int ncolumns , double *ndata){
	if(rows!=nrows || columns!=ncolumns){
		double *newData = NULL;
		try{
		newData = new double[nrows*ncolumns];
		} 
		catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
		rows=nrows;
		columns=ncolumns;
		for(int i=0; i<rows*columns; i++){
			newData[i]=ndata[i];
		}
	
		delete[] data;
		data = newData;
	}
	else{
	for(int i=0; i<rows*columns; i++){
		data[i]=ndata[i];
		}
	}
}
/*
Matrix& Matrix::operator=(const Matrix &m){
	cout << "\noperator przypisania\n";
    if(!(*this==m)){
        double *newData = NULL;
        try{
        newData = new double [m.size*m.size];
         } catch(bad_alloc &ba){
            cout << "Exception caught: " << ba.what()<< endl;
           return *this;
        }
        for(int i=0; i<m.size*m.size; i++){
          newData[i]=m.data[i];
        }
    }
	return *this;	
}

bool Matrix::operator==(const Matrix &m){
	if(this->size != m.size) return false;
	bool equal = true;
	for(int i=0; i < this->size*this->size; i++){
		if(this->data[i] != m.data[i]){
			equal=false;
			break;
		}	
	}
	return equal;
}
*/
//Cref
rcMatrix::Cref::Cref(rcMatrix& mm, unsigned int rr,unsigned int cc):m(mm), row(rr), col(cc){} 

rcMatrix::Cref::operator double() const{
	cout << "operator double() const\n";
	return m.read(row,col);
}

rcMatrix::Cref& rcMatrix::Cref::operator=(double d){
	cout << "operator=(double d)\n";
	m.write(row,col,d);
	return *this;
}

rcMatrix::Cref& rcMatrix::Cref::operator=(const rcMatrix::Cref& ref){
	return operator=((double)ref);
}

//rcMatrix

rcMatrix::rcMatrix(unsigned int row, unsigned int column){
	matrix = new Matrix(row, column);
}

rcMatrix::rcMatrix(const rcMatrix &m){
	m.matrix->rc++;
	matrix = m.matrix;
}

rcMatrix::rcMatrix(const char* fileName){
	matrix = new Matrix( fileName);
}

rcMatrix::rcMatrix(const double d){
	matrix = new Matrix(d);
}

rcMatrix::rcMatrix(){
	matrix = new Matrix();

}

rcMatrix::~rcMatrix(){
	if(--matrix->rc==0) delete matrix;
}

rcMatrix& rcMatrix::operator=(const rcMatrix& m){
	m.matrix->rc++;
	if(--matrix->rc == 0) delete matrix;
	matrix=m.matrix;
	return *this;
}	

//rcMatrix operator= (const double n, rcMatrix &m){} 129 

bool rcMatrix::operator==(const rcMatrix &m){
	if(this->matrix==m.matrix) return true;
	else return false;
}

ostream & operator << (ostream & s, const rcMatrix &m){
	s << endl;
	for(int i=0; i < m.matrix->rows*m.matrix->columns; i++){
		s << m.matrix->data[i] << "\t" ;
		if((i % m.matrix->columns) == (m.matrix->columns-1)) s << endl;
	}
	return s; 
}

//147-161
rcMatrix rcMatrix::operator+(const rcMatrix &m)const{
	if(this->matrix->rows!=m.matrix->rows && this->matrix->columns!=m.matrix->columns){
		throw InequalSize();
		}
	rcMatrix mat(this->matrix->rows, this->matrix->columns);
		for(int i=0; i < mat.matrix->rows*mat.matrix->columns; i++){
			mat.matrix->data[i] = this->matrix->data[i] + m.matrix->data[i];
		}
	return mat;
}

rcMatrix& rcMatrix::operator+=(const rcMatrix &m){
	Matrix *mat = new Matrix(this->matrix->rows, this->matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this + m;
	return *this;
}


rcMatrix rcMatrix::operator-(const rcMatrix &m)const{
	if(this->matrix->rows!=m.matrix->rows && this->matrix->columns!=m.matrix->columns){
		throw InequalSize();
		}
	rcMatrix mat(this->matrix->rows, this->matrix->columns);
		for(int i=0; i < mat.matrix->rows*mat.matrix->columns; i++){
			mat.matrix->data[i] = this->matrix->data[i] - m.matrix->data[i];
		}
	return mat;
}

rcMatrix& rcMatrix::operator-=(const rcMatrix &m){
	Matrix *mat = new Matrix(this->matrix->rows, this->matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this - m;
	return *this;
}

rcMatrix rcMatrix::operator*(const rcMatrix &m)const{
	if(this->matrix->columns!=m.matrix->rows){
		throw InequalSize();
	}
	
	rcMatrix mat(this->matrix->rows, m.matrix->columns);
		for(int r=0; r < mat.matrix->rows; r++){
			for(int c=0; c < mat.matrix->columns; c++){
				int sum=0;
				for(int k=0; k < this->matrix->columns; k++){
					sum += this->matrix->data[this->index(r,k)] * m.matrix->data[m.index(k,c)];
				}
				mat.matrix->data[mat.index(r,c)]=sum;		
			}
		}
	return mat;
}

rcMatrix& rcMatrix::operator*=(const rcMatrix &m){
	Matrix *mat = new Matrix(this->matrix->rows, m.matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this * m;
	return *this;
}



void rcMatrix::check(unsigned int row, unsigned int column) const{
	if((matrix->rows*matrix->columns)<=(int)index(row, column)) throw Range();
}

double rcMatrix::read(unsigned int row, unsigned int column ) const{
	return matrix->data[index(row, column)];
}

void rcMatrix::write(unsigned int row, unsigned int column, double d){
	matrix = matrix->detach();
	matrix->data[index(row, column)] = d;
}

double rcMatrix::operator()(unsigned int row, unsigned int column) const{
	cout<<"\noperator() const\n";
	try{
	check(row, column);
	}
	catch(Range &r){
		cout << "Exception caught: index out of range"<< endl;
	}
	return matrix->data[index(row, column)];
}

rcMatrix::Cref rcMatrix::operator()(unsigned int row, unsigned int column){
	cout<<"\noperator() Cref\n";
	try{
	check(row, column);
	}
	catch(Range &r){
		cout << "Exception caught: index out of range"<< endl;
	}
	return Cref(*this, row, column);
}

int rcMatrix::getRc(){
	return rcMatrix::matrix->rc;
}


bool rcMatrix::Matrix::operator==(const Matrix &m){
	if(this->rows != m.rows || this->columns != m.columns) return false;
	bool equal = true;
	for(int i=0; i < this->rows*this->columns; i++){
		if(this->data[i] != m.data[i]){
			equal=false;
			break;
		}	
	}
	return equal;
}


unsigned int rcMatrix::index(const unsigned int row, const unsigned int column) const{//numered from 0
	return matrix->columns*row+column;	
}
