#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>


//YOUR CODE GOES HERE!
template <typename T>
class Matrix{
 private:
  int numRows;
  int numColumns;
  std::vector<T> ** rows;
//std::vector<vector<T>* >* rows;
 public:
Matrix(): numRows(0), numColumns(0){
}
 Matrix(int r, int c): numRows(r), numColumns(c), rows(new std::vector<T>* [r]){
    //vector<T>* temp = new vector<T>(c, 0);
    for (int i = 0; i < r; i++){
      //rows[i] = new std::vector<T>(c, 0);
      rows[i] = new std::vector<T>(c);
    }
  }
 Matrix(const Matrix<T> & rhs): numRows(rhs.numRows), numColumns(rhs.numColumns), rows(new std::vector<T>* [numRows]){
    for (int i = 0; i < numRows; i++){
      rows[i] = new std::vector<T>(*rhs.rows[i]);
    }
  }
  ~Matrix(){
    if (numRows != 0){
      for (int i = 0; i < numRows; i++){
	delete rows[i];
      }
      delete[] rows;
    }
  }
  Matrix<T> & operator=(const Matrix<T> & rhs){
    if(this != &rhs){
      if (numRows != 0){
	for (int i = 0; i < numRows; i++){
	  delete rows[i];
	}
	delete[] rows;
      }
      numRows = rhs.numRows;
      numColumns = rhs.numColumns;
      rows = new std::vector<T> *[numRows];
      for (int i = 0; i < numRows; i++){
	rows[i] = new std::vector<T>(*rhs.rows[i]);
      }
    }
    return *this;
  }
  int getRows() const{
    return numRows;
  } 
  int getColumns() const{
    return numColumns;
  }
  std::vector<T> & operator[](int index){
    assert(index >= 0 && index < numRows);
    return *(rows[index]);
  }
  const std::vector<T> & operator[](int index) const{
    assert(index >= 0 && index < numRows);
    return *(rows[index]);
  }
  bool operator==(const Matrix<T> & rhs) const{
    if (numRows != rhs.numRows || numColumns != rhs.numColumns)
      return false;
    for (int i = 0; i < numRows; i++){
      if (*(rows[i]) != rhs[i])
	return false;
    }
    return true;
  }
  Matrix<T>  operator+(const Matrix<T> & rhs) const{
    assert(numRows == rhs.numRows && numColumns == rhs.numColumns);
    for (int i = 0; i < numRows; i++){
      for (int j = 0; j < numColumns; j++){
	(*(rows[i]))[j] += rhs[i][j];
      }
    }
    return *this;
  }
  friend std::ostream & operator<<(std::ostream &s, const Matrix<T> & rhs){
    s << "[ ";
    int i;
    for (i = 0; i < rhs.numRows; i++){
      s << "{";
      for (int j = 0; j < rhs.numColumns; j++){
	if (i < rhs.numRows - 1){
	  if (j < rhs.numColumns - 1){
	    s << rhs[i][j] << ", ";
	  }
	  else
	    s << rhs[i][j] <<"},"<< std::endl;
	}
	else{
	  if (j < rhs.numColumns - 1){
	    s << rhs[i][j] << ", ";
	  }
	  else
	    s << rhs[i][j] << "}";
	}
      }
    }
    s << " ]";
    return s;
  }
};
    
#endif
