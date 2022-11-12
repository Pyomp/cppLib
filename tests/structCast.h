#include <iostream>

void structCastTest() {
    struct YO {
        char a = 'y';
        char b = 'o';
        char end = '\0';
    } yo;

    std::cout << (char*) &yo << std::endl;
}