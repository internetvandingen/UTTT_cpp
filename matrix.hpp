#ifndef __MATRIX_HPP_INCLUDED__
#define __MATRIX_HPP_INCLUDED__

#include <vector>
#include <iostream>

// from: https://stackoverflow.com/questions/34277827/passing-a-2d-array-of-unknown-size-to-a-function-c

template<class TYPE>
class Matrix
{
private:
    int rows, columns;
    std::vector<TYPE> matrix;
public:
    // no default constructor. Matrix is BORN ready.

    Matrix(int numrows, int numcols):
        rows(numrows), columns(numcols), matrix(rows * columns)
    {
    }
// vector handles the Rule of Three for you. Don't need copy and move constructors
// a destructor or assignment and move operators

    // element accessor function
    TYPE & operator()(int row, int column)
    {
        // check bounds here
        return matrix[row * columns + column];
    }

    // constant element accessor function
    TYPE operator()(int row, int column) const
    {
        // check bounds here
        return matrix[row * columns + column];
    }

    // stupid little getter functions in case you need to know how big the matrix is
    int getRows() const
    {
        return rows;
    }
    int getColumns() const
    {
        return columns;
    }

    // and a handy-dandy stream output function
    friend std::ostream & operator<<(std::ostream &  out, const Matrix & in)
    {
        for (int i = 0; i < in.getRows(); i++)
        {
            for (int j = 0; j < in.getColumns(); j++)
            {
                out << in(i,j) << ' ';
            }
            out << '\n';
        }

        return out;
    }

};

#endif
