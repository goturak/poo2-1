#include <iostream>
#include "Matrix.h"
int main() {

    Matrix* m= new Matrix(3,4,6);
    Matrix* m2 = new Matrix(*m);
    std::cout << *m << std::endl;
    std::cout << *m2 << std::endl;
    std::cout << m << " / "<< m2;
    return 0;
}