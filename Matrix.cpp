//
// Created by goturak on 21/02/19.
//

#include "Matrix.h"

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
    if(x>=0&&x < width && y>=0&&y<height){
        elements[y][x]= value % modulo;
    }
}

int Matrix::getElement(int x, int y)const{
    if(x>=0&&x < width && y>=0&&y<height){
        return elements[y][x];
    }
    return -1;
}

Matrix::Matrix(int width, int height, int modulo) : width(width), height(height), modulo(modulo) {
    elements = new int*[height];
    srand(time(NULL));

    for(int i =0;i<height;i++){
        elements[i]= new int[width];
        for(int j=0; j <width; j++){
            setElement(j,i,std::rand());
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    os<<"{";
    for(int i=0;i<m.height;i++){
        os<<"{";
        for (int j = 0; j <m.width ; j++) {
            os<< m.getElement(j,i);
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


