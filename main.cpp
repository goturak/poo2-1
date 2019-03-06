#include <iostream>
#include "Matrix.hpp"
int main() {

    Matrix* m= new Matrix(3,4,6);
    Matrix* m2 = new Matrix(*m);
    std::cout << *m << std::endl << std::endl;
    std::cout << *m2 << std::endl << std::endl;
    std::cout << m << " / "<< m2 << std::endl;
    m2->resize(5,5);
    std::cout << m2 << std::endl;
    std::cout << *m2;
    return 0;
}