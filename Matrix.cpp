//
// Created by goturak on 21/02/19.
//
#include <iostream>
#include <unistd.h>
#include "Matrix.hpp"

#include "Operation.hpp"
#include "Addition.h"
#include "Multiplication.h"
#include "Substraction.h"


int **Matrix::getElements() const {
    return elements;
}

int Matrix::getWidth() const {
    return width;
}



int Matrix::getHeight() const {
    return height;
}



int Matrix::getModulo() const {
    return modulo;
}

void Matrix::setElement(int x, int y, int value){
    if(x >= 0 && x < height && y >= 0 && y < width){
        elements[x][y]= ((value % modulo) + modulo) % modulo;
    }
}

int Matrix::getElement(int x, int y)const{
    if(x >= 0 && x < height && y >=0 && y < width){
        return elements[x][y];
    }else if(y >=0&&x >= 0){
        return 0;
    }
    return -1;
}

void Matrix::resize(int h, int w) {
    int** newElements = new int*[h];

    for(int i = 0; i < h; i++){
        newElements[i] = new int[w];
        for(int j = 0; j < w; j++){
            if(i < height && j < width) {
                newElements[i][j] = elements[i][j];
            } else {
                newElements[i][j] = 0;
            }
        }
    }
    this->elements = newElements;
    this->height = h;
    this->width = w;
}

Matrix::Matrix(int height, int width, int modulo) : height(height), width(width), modulo(modulo) {
    elements = new int*[height];

    srand(time(NULL));

    for(int i = 0; i < height; i++){
        elements[i] = new int[width];
        for(int j = 0; j < width; j++){
            setElement(i, j, std::rand());
        }
    }
}

Matrix::Matrix(const Matrix &m2) : width(m2.getWidth()), height(m2.getHeight()), modulo(m2.getModulo()) {
    elements = new int*[height];

    for(int i = 0; i < height; i++){
        elements[i] = new int[width];
        for(int j = 0; j < width; j++){
            setElement(i, j, m2.getElement(i, j));
        }
    }
}


std::ostream &operator<<(std::ostream &os, const Matrix &m) {

    for(int i=0;i<m.height;i++){
        for (int j = 0; j <m.width ; j++) {
            os << m.getElement(i,j);
            if(j<m.width-1){
                os <<" ";
            }
        }

        if(i<m.height-1){
            os<< std::endl;
        }

    }
    return os;
}

void Matrix::compute(Matrix &result,Matrix &m2, Operation *op ) {
    if(!result.sameMod(m2)){
        throw std::invalid_argument("modulos are not equal");
    }
    int maxHeight= std::max(getHeight(),m2.getHeight());
    int maxWidth= std::max(getWidth(),m2.getWidth());
    result.resize(maxHeight,maxWidth);
    for (int i = 0; i < maxHeight; i++) {
        for(int j= 0; j<maxWidth;j++){
            int elem1= getElement(i,j);
            int elem2=m2.getElement(i,j);
            result.setElement(i,j, op->apply(elem1,elem2));
        }
    }

}
bool Matrix::sameMod(Matrix &m2) {
    return getModulo()==m2.getModulo();
}


void Matrix::addInPlace(Matrix &m2) {
    Addition *op= new Addition();
    compute(*this, m2, op);
    delete( op);
}

Matrix *Matrix::addPtr(Matrix &m2) {
    Addition *op= new Addition();
    Matrix *result=new Matrix(getHeight(),getWidth(),getModulo());
    compute(*result,m2,op);
    delete( op);
    return result;
}

Matrix Matrix::addValue(Matrix &m2) {
    Addition *op= new Addition();
    Matrix result(getHeight(),getWidth(),getModulo());
    compute(result,m2,op);
    delete( op);
    return result;
}



void Matrix::multInPlace(Matrix &m2) {
    Multiplication *op= new Multiplication();
    compute(*this, m2, op);
}

Matrix *Matrix::multPtr(Matrix &m2) {
    Multiplication *op= new Multiplication();
    Matrix *result=new Matrix(getHeight(),getWidth(),getModulo());
    compute(*result,m2,op);
    delete( op);
    return result;
}


Matrix Matrix::multValue(Matrix &m2) {
    Multiplication *op= new Multiplication();
    Matrix result(getHeight(),getWidth(),getModulo());
    compute(result,m2,op);
    delete( op);
    return result;

}



void Matrix::subInPlace(Matrix &m2) {
    Substraction *op= new Substraction();
    compute(*this, m2, op);
    delete( op);
}

Matrix *Matrix::subPtr(Matrix &m2) {
    Substraction *op= new Substraction();
    Matrix *result=new Matrix(getHeight(),getWidth(),getModulo());
    compute(*result,m2,op);
    delete( op);
    return result;
}

Matrix Matrix::subValue(Matrix &m2) {
    Substraction *op= new Substraction();
    Matrix result(getHeight(),getWidth(),getModulo());
    compute(result,m2,op);
    delete( op);
    return result;
}

Matrix::~Matrix() {
    std::cout << "Destructor is executed\n";
    for(int i =0;i<height;i++){
        delete [] elements[i];
    }
    delete [] elements;
}



