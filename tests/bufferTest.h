#include <iostream>
#include <string>

namespace bufferTest {
    void runTest() {
        char a[8];
        std::string buffer(a, 8);
        for (size_t i = 0; i < 8; i++)
        {
            a[i] = 0;
        }

        uint32_t* p = (uint32_t*)buffer.c_str();

        p[0] = 5555;

        std::cout << *((uint32_t*)buffer.c_str()) << std::endl;
    }
}