//
// Created by goturak on 21/02/19.
//

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
        elements[x][y]= value % modulo;
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
    os<<"{";
    for(int i=0;i<m.height;i++){
        os<<"{";
        for (int j = 0; j <m.width ; j++) {
            os<< m.getElement(i,j);
            if(j<m.width-1){
                os <<",";
            }
        }
        os<<"}";
        if(i<m.height-1){
            os<<","<< std::endl;
        }

    }
    os<<"}";
    return os;
}


void Matrix::calculateInPlace(Matrix &m2, Operation *op ) {
    if(!sameMod(m2)){
        throw std::invalid_argument("modulos are not equal");
    }
    int maxHeight= std::max(getHeight(),m2.getHeight());
    int maxWidth= std::max(getWidth(),m2.getWidth());
    resize(maxHeight,maxWidth);
    for (int i = 0; i < maxHeight; i++) {
        for(int j= 0; j<maxWidth;j++){
            int elem1= getElement(i,j);
            int elem2=m2.getElement(i,j);
            setElement(i,j, op->apply(elem1,elem2));
        }
    }
}

void Matrix::calculateWithReturn(Matrix &m2, Operation *op ) {
    if(!sameMod(m2)){
            throw std::invalid_argument("modulos are not equal");
    }
    int maxHeight= std::max(getHeight(),m2.getHeight());
    int maxWidth= std::max(getWidth(),m2.getWidth());
    Matrix *result= new Matrix(maxHeight, maxWidth, getModulo());
    for (int i = 0; i < maxHeight; i++) {
        for(int j= 0; j<maxWidth;j++){
            int elem1= getElement(i,j);
            int elem2=m2.getElement(i,j);
            setElement(i,j, op->apply(elem1,elem2));
        }
    }
}



void Matrix::addInPlace(Matrix &m2) {
    Addition *op= new Addition();
    calculateInPlace(m2,op);
}

void Matrix::multInPlace(Matrix &m2) {
    Multiplication *op= new Multiplication();
    calculateInPlace(m2,op);
}

void Matrix::subInPlace(Matrix &m2) {
    Substraction *op= new Substraction();
    calculateInPlace(m2,op);
}

bool Matrix::sameMod(Matrix &m2) {
    return getModulo()==m2.getModulo();
}

