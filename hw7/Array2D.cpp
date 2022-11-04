#include <iostream>
#include <cstdlib>
#include "Array2D.H"

// This constructor is delegated to by other constructors and does all of the 
// allocation, showing an example of a delegating constructor..  
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {

   ary = new int*[numRows];
   for (int i = 0; i < numRows; i++) {
      ary[i] = new int[numCols];
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

bool Array2D::sameSize(const Array2D& other) const {
   return (numRows == other.getNumRows( ) && numCols == other.getNumCols( ));
}

void Array2D::deleteAry(int** ary) {
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}

Array2D::Array2D(const Array2D& other)
{
    *this = other;
}

Array2D::~Array2D()
{
    deleteAry(this->ary);
}

int Array2D::getNumRows() const
{
    return numRows;
}

int Array2D::getNumCols() const
{
    return numCols;
}

Array2D& Array2D::operator= (const Array2D& a1)
{
    deleteAry(this->ary);
    this->numRows = a1.getNumRows();
    this->numCols = a1.getNumCols();
    ary = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        ary[i] = new int[numCols];
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            this->ary[i][j] = a1.ary[i][j];
        }
    }
    return *this;
}

bool Array2D::operator== (const Array2D& a1)
{
    if (this->numRows != a1.numRows) return false;
    if (this->numCols != a1.numCols) return false;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if(this->ary[i][j] != a1.ary[i][j]) return false;
        }
    }
    return true;
}

Array2D Array2D::operator* (const Array2D& a1)
{
    if (this->numCols != a1.numRows)
    {
        return Array2D(this->numRows, this->numCols, 'c');
    }
    Array2D ret = Array2D(this->numRows, a1.numCols, 'c');
    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < a1.numCols; j++)
        {
            int val = 0;
            for (int k = 0; k < this->numCols; k++)
            {
                val += (ary[i][k] * a1.ary[k][j]);
            }
            ret.ary[i][j] = val;
        }
    }
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Array2D& a1)
{
    for (int i = 0; i < a1.getNumRows(); i++)
    {
        for (int j = 0; j < a1.getNumCols(); j++)
        {
            os << a1.getVal(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

int Array2D::getVal(int row, int col) const
{
    return ary[row][col];
}





