#ifndef STACK_H
#define STACK_H

#include <list>

template <class T>
class Stack
{
public:
    Stack();
    void push(T val);
    T peek();
    T pop();
    bool empty();

private:
    std::list<T> l;
};

template <class T>
Stack<T>::Stack()
{
    l = std::list<T>();
}

template <class T>
void Stack<T>::push(T val)
{
    l.push_back(val);
}

template <class T>
T Stack<T>::peek()
{
    return l.back();
}

template <class T>
T Stack<T>::pop()
{
    T result = l.back();
    l.pop_back();
    return result;
}

template <class T>
bool Stack<T>::empty()
{
    return l.empty();
}

#endif // STACK_H
