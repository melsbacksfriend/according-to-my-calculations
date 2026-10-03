#ifndef QUEUE_H
#define QUEUE_H

#include <list>

template <class T>
class Queue
{
public:
    Queue();
    void push(T val);
    T peek();
    T pop();
    bool empty();

private:
    std::list<T> l;
};

// All this Queue<T> stuff is funny because it sounds like Qt and I'm using Qt Creator as my IDE
template <class T>
Queue<T>::Queue()
{
    l = std::list<T>();
}

template <class T>
void Queue<T>::push(T val)
{
    l.push_back(val);
}

template <class T>
T Queue<T>::peek()
{
    return l.front();
}

template <class T>
T Queue<T>::pop()
{
    T result = l.front();
    l.pop_front();
    return result;
}

template <class T>
bool Queue<T>::empty()
{
    return l.empty();
}

#endif // QUEUE_H
