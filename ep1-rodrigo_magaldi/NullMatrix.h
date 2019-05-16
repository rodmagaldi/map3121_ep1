#ifndef NULLMATRIX_H
#define NULLMATRIX_H

#include "Matrix.h"


class NullMatrix : public Matrix
{
    public:
        NullMatrix(int, int, int);
        virtual ~NullMatrix();

    protected:

    private:
};

#endif // NULLMATRIX_H
