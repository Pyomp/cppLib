#include <iostream>

void structCastTest() {
    struct YO {
        char a = 'y';
        char b = 'o';
    } yo;

    std::cout << (char*) &yo << std::endl;
}