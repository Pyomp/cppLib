#pragma once

#include <functional>

template<typename FunctorEventType>
struct Functor {
    Functor<FunctorEventType>* prev;
    std::function<void(FunctorEventType)> cb;
    Functor<FunctorEventType>* next;
};

template<typename EventType>
class EventSet {
public:
    virtual ~EventSet() { this->clear(); };

    void emit(EventType event) {
        Functor<EventType>* a = this->last;
        while (a->prev) {
            a->cb(event);
            a = a->prev;
        }
    };

    Functor<EventType>* add(std::function<void(EventType)> cb) {
        Functor<EventType>* a = new Functor<EventType>{ this->last, cb };
        // std::cout << "new " << a << std::endl;
        this->last->next = a;
        this->last = a;
        return a;
    };

    void remove(Functor<EventType>* fn) {
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
    Functor<EventType>* last = new Functor<EventType>{ 0, 0 };
};
