#pragma once

#include <iostream>
#include <thread>  
#include <memory>  

class SafetyThreadTest : public std::enable_shared_from_this<SafetyThreadTest> {

public:
    static void createObject() {
        auto safetyTest = std::make_shared<SafetyThreadTest>();
        safetyTest->runThread();
        std::cout << safetyTest->a << std::endl;
        std::cout << "end test" << std::endl;
    }

    static void runTest() {
        SafetyThreadTest::createObject();
        sleep(1.5);
    }

    virtual ~SafetyThreadTest() { std::cout << "destroyed" << std::endl; };

    int a = 1;

    void runThread() {
        auto sharedPointer = this->shared_from_this();
        std::thread one(
            [sharedPointer]() {
                sleep(1);
                sharedPointer->displayState();
            }
        );
        one.detach();
    };

private:
    void displayState() {
        std::cout << this->a << std::endl;
    };
};
