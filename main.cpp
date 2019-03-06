#include <iostream>

#include "Matrix.hpp"
int main() {

    Matrix* m= new Matrix(3,4,6);


    Matrix* m2 = new Matrix(5,4,6);


    Matrix* m3= m->addPtr(*m2);

    Matrix m4= m->addValue(*m2);
   std::cout<< "m1\n" << *m << std::endl<<std::endl;
    std::cout<< "m2\n"  << *m2 << std::endl<<std::endl;
    std::cout<< "m3\n"  << *m3 << std::endl<<std::endl;
    std::cout<< "m4\n"  << m4 << std::endl<<std::endl;

    std::cout<< "m1\n" << *m << std::endl<<std::endl;
    m->addInPlace(*m2);

    std::cout<< "m1 after in place op\n" << *m << std::endl<<std::endl;

    delete(m);
    delete(m2);
    delete(m3);




    exit(0);
}