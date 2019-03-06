#include <iostream>
#include "Matrix.h"
int main() {

    Matrix* m= new Matrix(3,4,6);
    std::cout << *m;
    return 0;
}