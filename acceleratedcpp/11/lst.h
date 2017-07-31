// A container that mimics the stl list class.
#ifndef __GUARD_LST_H__
#define __GUARD_LST_H__

#include <algorithm>
#include <cstddef>
#include <memory>

// List node.
template <class T>
class node {
public:
    node(): val(0), next(0), prev(0) {};
    node(T& v): next(0), prev(0), val(&v) {};
    T* val;
    node* next;
    node* prev;
};

// Iterator over list nodes.
template <class T>
class nodeiter {
public:
    nodeiter(): current(0) {};
    nodeiter(node<T>& n) { current = &n; };

    nodeiter& operator++() { current = current->next; return *this; };
    nodeiter& operator--() { current = current->prev; return *this; };
    nodeiter operator++(int) { current = current->next; return *this; };
    nodeiter operator--(int) { current = current->prev; return *this; };

    T& operator*() { return *(current->val); };
    T* operator->() { return current->val; };

    node<T>* current;
};

template <class T>
bool operator==(const nodeiter<T> &n1, const nodeiter<T> &n2) {
    return n1.current == n2.current;
}

template <class T>
bool operator!=(const nodeiter<T> &n1, const nodeiter<T> &n2) {
    return !(n1.current == n2.current);
}
////===================================================================
//// Define a list class.
////===================================================================
template <class T>
class Lst {
public:
    typedef nodeiter<T> iterator;
    node<T>* head;
    node<T>* tail;
    iterator begin() { return iterator(*head); };
    iterator end() { return iterator(*tail); };

    Lst(): head(0), tail(0) {};
    Lst(T& val) { create(val); };

    void prepend(T& val) {
        if (head == 0) {
            create(val);
        } else {
            node<T>* newnode = new node<T>(val);
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void append(T& val) { 
        if (head == 0) {
            create(val);
        } else {
            node<T>* newnode = new node<T>(val);
            tail->prev->next = newnode;
            newnode->next = tail;
            tail->prev = newnode;
        }
    }

private:
    void create(T& val) {
        head = new node<T>(val);
        tail = new node<T>;
        head->next = tail;
        tail->prev = head;
    }
};
#endif
