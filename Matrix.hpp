//
// Created by goturak on 21/02/19.
//

#ifndef POO2_MATRIX_H
#define POO2_MATRIX_H


#include <ostream>

class Matrix {
public:
    int **getElements() const;

    int getWidth() const;


    int getHeight() const;



    int getModulo() const;

    void setElement(int x, int y, int value);
    int getElement(int x, int y) const;


    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);



    Matrix(int height, int width, int modulo);

    Matrix(const Matrix &m2);


private:
    int width;
    int height;
    int modulo;
    int** elements;


};


#endif //POO2_MATRIX_H
