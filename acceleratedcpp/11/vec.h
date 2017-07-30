// A container that mimics the stl vector class.
#ifndef __GUARD_VEC_H__
#define __GUARD_VEC_H__

#include <algorithm>
#include <cstddef>
#include <memory>

template <class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    // Constructors and destructor.
    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }

    // Random access operator.
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const {return data[i]; }

    // Other functions.
    void push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    iterator clear();

    size_type size() const {return avail - data; }

    iterator begin() { return data; }
    const iterator end() const { return avail; }

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {

    // If self-assigning, do nothing.
    if (&rhs != this) {
        // Free he lhs array.
        uncreate();

        // Copy.
        create(rhs.begin(), rhs.end());
    }
    return *this;
};


template <class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}


template <class T>
void Vec<T>::create(size_type n, const T& item) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, item);
}


template <class T>
void Vec<T>::create(const_iterator b, const_iterator e) {
    data = alloc.allocate(e - b);
    limit = avail = std::uninitialized_copy(b, e, data);
}


template <class T>
void Vec<T>::uncreate() {
    if (data) {
        // Destroy in reverse order.
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        // Return the space.
        alloc.deallocate(data, limit - data);
    }
    // Reset the pointers.
    data = limit = avail = 0;
}


template <class T>
void Vec<T>::grow() {
    // Double the space.
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    // Copy.
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // Deallocate old elements.
    uncreate();

    // Reset the pointers.
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}


template <class T>
void Vec<T>::unchecked_append(const T& item) {
    alloc.construct(avail++, item);
}


template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator first,
    Vec<T>::iterator last) {
    if (last < avail)
        std::copy(last, avail, first);
    for (Vec<T>::iterator it = avail - (last - first); it < avail; ++it)
        alloc.destroy(it);
    avail -= (last - first);
    return first;
}


template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator position) {
    return erase(position, position + 1);
}


template <class T>
typename Vec<T>::iterator Vec<T>::clear() {
    return erase(data, avail);
}
#endif
