#include <iostream>

#include "../StringBuffer.h"

using namespace std;

namespace stringBufferTest {
    void run() {
        const size_t SIZE = 19;

        StringBuffer stringBuffer(SIZE);

        cout << "It should be initialized to 0 ";

        for (size_t i = 0; i < SIZE; i++) {
            if (stringBuffer.getUint8(i) != 0) {
                cout << "FAIL" << endl;
                break;
            }
            if (i == SIZE - 1) cout << "PASS" << endl;
        }

        cout << "It should return 0 when trying getting overflow buffer ";

        if (
            stringBuffer.getUint8(SIZE + 1) == 0
            && stringBuffer.getUint16(SIZE + 1) == 0
            && stringBuffer.getUint32(SIZE + 1) == 0
            && stringBuffer.getFloat32(SIZE + 1) == 0
            && stringBuffer.getUint64(SIZE + 1) == 0
            ) cout << "PASS" << endl;
        else cout << "FAIL" << endl;

        cout << "It should set get data ";

        size_t offset = 0;
        offset += stringBuffer.setUint8(123, 0);
        offset += stringBuffer.setUint16(123, offset);
        offset += stringBuffer.setUint32(123, offset);
        offset += stringBuffer.setUint64(123, offset);
        offset += stringBuffer.setFloat32(123, offset);

        if (
            stringBuffer.getUint8(0) == 123
            && stringBuffer.getUint16(1) == 123
            && stringBuffer.getUint32(3) == 123
            && stringBuffer.getUint64(7) == 123
            && stringBuffer.getFloat32(15) == 123
            ) cout << "PASS" << endl;
        else cout << "FAIL" << endl;

        uint8_t a = stringBuffer.getUint8(0);

        cout << (void*)&stringBuffer << endl;
        cout << (void*)&a << endl;
    }
}
