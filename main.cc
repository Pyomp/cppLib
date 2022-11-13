#include <iostream>

// #include "SafetyThreadTest.h"
// #include "terminal.h"
// #include "structCast.h"
// #include "EventSet.h"
// #include "EventSetVoid.h"
#include "stringBufferUtils.h"
#include <cstring>
int main() {
    float a = 97.998798;
    char s[4];

    std::memcpy(&s, &a, 4);
    std::string str(s, 4);
    // std::cout << stringBufferUtils::getString(str, 4, 2) << std::endl;
    // std::cout << (int)stringBufferUtils::getUint8(str, 4) << std::endl;
    // std::cout << stringBufferUtils::getUint16(str, 2) << std::endl;
    std::cout << stringBufferUtils::getFloat32(str, 0) << std::endl;
    std::cout << a << std::endl;
    return 0;
}