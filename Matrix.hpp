//
// Created by goturak on 21/02/19.
//

#ifndef POO2_MATRIX_H
#define POO2_MATRIX_H


#include <ostream>
#include "Operation.hpp"

class Matrix {
public:
    int **getElements() const;

    int getWidth() const;


    int getHeight() const;



    int getModulo() const;

    void setElement(int x, int y, int value);
    int getElement(int x, int y) const;

    void resize(int h, int w);


    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);



    Matrix(int height, int width, int modulo);

    Matrix(const Matrix &m2);

    void addInPlace(Matrix& m2);
    Matrix* addPtr(Matrix &m2);
    void multInPlace(Matrix& m2);
    void subInPlace(Matrix& m2);

private:
    int width;
    int height;
    int modulo;
    int** elements;


    bool sameMod(Matrix& m2);
    void compute(Matrix &result,Matrix &m2, Operation *op );
    void calculateInPlace(Matrix& m2, Operation* op);
    Matrix* calculateWithReturn(Matrix &m2, Operation *op );
};


#endif //POO2_MATRIX_H
