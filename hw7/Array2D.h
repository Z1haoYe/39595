#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 
   Array2D(const Array2D& other);

   ~Array2D();
   int getNumRows() const;
   int getNumCols() const;

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;
   virtual Array2D& operator= (const Array2D& a1);
   virtual bool operator== (const Array2D& a1);
   virtual Array2D operator* (const Array2D& a1);
   int getVal(int row, int col) const;

private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;

   int numRows;
   int numCols;
   int** ary;
};

std::ostream& operator<<(std::ostream&, const Array2D& a1);
#endif /* ARRAY2D_H_ */
