// A container that mimics the stl list class.
#ifndef __GUARD_LST_H__
#define __GUARD_LST_H__

#include <algorithm>
#include <cstddef>
#include <memory>

template <class T> class Lst_node {
    public:
        // Default constructor: all pointers are NULL.
        Lst_node(): val(0), next(0), prev(0) {};

        // Comparison and dereference use this->val.
        T* operator*() { return val; };
        Lst_node* operator++() {
            return next;
        }
        Lst_node* operator--() {
            return prev;
        }
        T* val;
        Lst_node* next;
        Lst_node* prev;
};


template <class T> class Lst {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    // Default constructor.
    Lst() { head = tail = Lst_node<T>(); }
    // Copy constructor.
    Lst(const Lst& l) { }
    // Assignment constructor.
    Lst& operator=(const Lst&);
    // Destructor.
    ~Lst() { uncreate(); }

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    iterator insert(T*, iterator position);
    iterator clear();

    size_type size() const {return tail - head; }

    iterator begin() { return head; }
    const iterator end() const { return tail; }

private:
    Lst_node<T> head;
    Lst_node<T> tail;

    std::allocator<Lst_node<T>> alloc;
};
#endif
