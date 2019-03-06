#include <iostream>

#include "Matrix.hpp"
int main() {

    Matrix* m= new Matrix(3,4,6);


    Matrix* m2 = new Matrix(5,4,6);

    std::cout << *m << std::endl<<std::endl;
    std::cout << *m2 << std::endl<<std::endl;

    m->multInPlace(*m2);
    std::cout << *m ;



    return 0;
}