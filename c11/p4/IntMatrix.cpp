#include "IntMatrix.h"

IntMatrix::IntMatrix(): numRows(0), numColumns(0){
  //initialize the matrix to have 0 rows and 0 columns
}
IntMatrix::IntMatrix(int r, int c) {
  //takes the number of rows and columns
  numRows = r;
  numColumns = c;
  rows = new IntArray *[numRows];
  for (int i = 0; i < numRows; i++){
    rows[i] = new IntArray(numColumns);
  } 
}
IntMatrix::IntMatrix(const IntMatrix & rhs)  {
  //copy constructor 
  numRows = rhs.numRows;
  numColumns = rhs.numColumns;
  rows = new IntArray * [numRows];
  for (int i = 0; i < numRows; i++){
    rows[i] = new IntArray(*rhs.rows[i]);
  }
}
IntMatrix::~IntMatrix() {
  //free all the memory the Matrix has allocated
  if (numRows != 0){
    for (int i = 0; i < numRows; i++){
      delete rows[i];
    }
    delete[] rows;
  }
}

IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {
  //assignment overloading
  assert(this != &rhs);
  if (numRows != 0){
    //IntArray ** temp = new IntArray* [rhs.numRows];
    for (int i = 0; i < numRows; i++){
      delete rows[i];
    }
    delete[] rows;
  }
  numRows = rhs.numRows;
  numColumns = rhs.numColumns;
  rows = new IntArray*[numRows];
  for (int i = 0; i < numRows; i++){
    rows[i] = new IntArray(* rhs.rows[i]);
  }
  return *this;
}
int IntMatrix::getRows() const {
  return numRows;
}
int IntMatrix::getColumns() const {
  return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
  assert((index >= 0) && (index < numRows));
  return *(rows[index]);
}
IntArray & IntMatrix::operator[](int index){
  assert((index >= 0) && (index < numRows));
  return *(rows[index]);
}

bool IntMatrix::operator==(const IntMatrix & rhs) const {
  if (numRows != rhs.numRows || numColumns != rhs.numColumns)
    return false;
  for (int i = 0; i < numRows; i++){
    if (*(rows[i]) != rhs[i])
      return false;
  }
  return true;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
  //IntMatrix *res = new IntMatrix(rhs.numRows, rhs.numColumns);
  assert((numRows == rhs.numRows) && (numColumns == rhs.numColumns));
  for (int i = 0; i < numRows; i++){
    for (int j = 0; j < numColumns; j++){
      (*(rows[i]))[j] += rhs[i][j];
      //std::cout << "rhs[i][j] is" << rhs[i][j] << std::endl; 
      //std::cout << "after operator+, res[i][j] is" << res->rows[i][j] << std::endl;
    }
  }
  return *this;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
  s << "[ ";
  int i;
  for (i = 0; i < rhs.getRows(); i++){
    if (i < rhs.getRows() - 1)
      s << rhs[i] << "," << std::endl;
    else
      s << rhs[i];
  }
  s << " ]";
  return s;
}
