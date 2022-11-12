#pragma once

#include <functional>

struct FunctorVoid {
    FunctorVoid* prev;
    std::function<void()> cb;
    FunctorVoid* next;
};

class EventSetVoid {
public:
    virtual ~EventSetVoid() { this->clear(); };

    void emit() {
        FunctorVoid* a = this->last;
        while (a->prev) {
            a->cb();
            a = a->prev;
        }
    };

    FunctorVoid* add(std::function<void()> cb) {
        FunctorVoid* a = new FunctorVoid{ this->last, cb };
        // std::cout << "new " << a << std::endl;
        this->last->next = a;
        this->last = a;
        return a;
    };

    void remove(FunctorVoid* fn) {
        if (fn == this->last) this->last = fn->prev;
        if (fn->next) fn->next->prev = fn->prev;
        if (fn->prev) fn->prev->next = fn->next;
        // std::cout << "delete " << fn << std::endl;
        delete fn;
    }

    void clear() {
        while (this->last) this->remove(this->last);
    }

private:
    FunctorVoid* last = new FunctorVoid{ 0, 0 };
};
