#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <stdexcept>

template <class T>
struct _LNode {
    T element;
    _LNode *next;
};


template <class T>
class LinkedList {
    private:
        struct _LNode<T> *root;
        size_t elements;
    public:
        LinkedList();
        ~LinkedList();

        size_t add(T element);
        size_t length();
        T pop();
        T get(size_t i);
        void remove(size_t i);
};

template <class T>
LinkedList<T>::LinkedList()
    : root(NULL), elements(0) 
{
}

template <class T>
LinkedList<T>::~LinkedList() {
    struct _LNode<T> *p;
    struct _LNode<T> *tmp;
    p = root;
    while(p) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
};


template <class T>
size_t LinkedList<T>::add(T element) {
    struct _LNode<T> *p;
    if(!root) {
        root = new struct _LNode<T>;
        root->element = element;
        root->next = NULL;
        return ++elements;
    }
    p = root;
    while(p->next) 
        p = p->next;

    p->next = new struct _LNode<T>;
    p = p->next;
    p->element = element;
    p->next = NULL;
    return ++elements;
}
    
template <class T>
size_t LinkedList<T>::length() {
    return elements;
}

template <class T>
T LinkedList<T>::pop() {
    struct _LNode<T> *p;
    struct _LNode<T> *tmp;
    T retval;
    if(elements <= 0) {
        throw std::out_of_range("No elements to pop");
    }
    tmp = p = root;
    while(tmp->next) {
        p = tmp;
        tmp = tmp->next;
    }
    retval = tmp->element;
    p->next = NULL;
    delete tmp;
    elements--;
    return retval;
}


template <class T>
T LinkedList<T>::get(size_t i) {
    struct _LNode<T> *p;
    if(i >= elements) {
        throw std::out_of_range("Index is out of range");
    }
    p = root;
    for(size_t j=0;j<i;j++)
        p = p->next;
    return p->element;
}

template <class T>
void LinkedList<T>::remove(size_t i) {
    struct _LNode<T> *p;
    struct _LNode<T> *tmp;
    if(i >= elements) {
        throw std::out_of_range("Index is out of range");
    }
    p = root;
    for(size_t j=0;j<i;j++) {
        tmp = p;
        p = p->next;
    }
    tmp->next = p->next;
    delete p;
    elements--;
}

#endif /* __NODE_H__ */
