#include <iostream>

// #include "SafetyThreadTest.h"
// #include "terminal.h"
#include "structCast.h"
int main() {
    // SafetyThreadTest::runTest();
    // terminal::init(false);
    // structCastTest();
    struct A{
        int y;
    };
    std::cout << sizeof(A) << std::endl;
    return 0;
}