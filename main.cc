#include <iostream>

#include "hello.h"
#include "SafetyThreadTest.h"
#include "terminal.h"


int main() {
    std::cout << hello() << std::endl;
    // SafetyThreadTest::runTest();
    terminal::init(false);
    return 0;
}