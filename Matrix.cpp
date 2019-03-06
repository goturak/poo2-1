//
// Created by goturak on 21/02/19.
//

#include "Matrix.hpp"

#include "Operation.hpp"


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
    }
    return -1;
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


