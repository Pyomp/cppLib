#include "EventSet.h"

void eventSetTest() {
    // SafetyThreadTest::runTest();
    // terminal::init(false);
    // structCastTest();
    struct A {
        int y = 10;
    };
    A a;
    EventSet<A> e;
    e.add([](A a) {std::cout << a.y << std::endl;});
    e.add([](A a) {std::cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << std::endl;});
    e.add([](A a) {std::cout << a.y << std::endl;});
    // e.remove(&p);
    e.emit(a);
    e.emit(a);
    // e.remove(p);
    e.emit(a);
    return 0;
}