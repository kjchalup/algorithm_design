// Template functions emulating standard library algorithms.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;

template <class T1, class T2> bool equal(T1 b, T1 e, T2 b2) {
    while (b != e)
        if (b++ != b2++)
            return false;
    return true;
}


template <class Iter, class T> Iter find(Iter b, Iter e, const T& x) {
    while (b != e)
        if (*b == x)
            return b;
    return e;
}


template <class In, class Out> Out mycopy(In b, In e, Out d) {
    while (b != e)
        *d++ = *b++;
    return d;
}


template <class In, class Out, class X>
Out remove_copy_if(In b, In e, Out d, bool p(X)) {
    while (b != e) {
        if (p(*b))
            *d++ = *b;
        b++;
    }
    return d;
}


template <class In, class Out, class X>
Out transform(In b, In e, Out d, X f(X&)) {
    while (b != e)
        *d++ = f(*b++);
    return d;
}


template <class Iter, class T> T accumulate(Iter b, Iter e, const T& t) {
    T res = t;
    while (b != e)
        res += *b;
    return res;
}


template <class Iter> Iter search(Iter b, Iter e, Iter b2, Iter e2) {
    while (b != e) {
        if (*b == *b2) {
            while (b2 != e2)
                if (*++b2 != *(b + e2 - b2))
                    break;
            if (b2 == e2)
                return b;
        }
        ++b;
    }
    return b;
}


template <class In, class T> In find_if(In b, In e, bool p(T)) {
    while (b != e) {
        if (p(*b))
            return b;
        ++b;
    }
    return b;
}


template <class In, class Out, class T> 
Out remove_copy(In b, In e, Out d, const T& t) {
    while (b != e) {
        if (*b != t)
            *d++ = *b;
        ++b;
    }
    return d;
}


template <class Iter, class T> Iter remove(Iter b, Iter e, const T& t) {
    Iter b_good = b;
    while (b != e) {
        if (!(*b == t))
            *b_good++ = *b;
        b++;
    }
    return b_good;
}


template <class Iter, class Pred>
    Iter partition (Iter first, Iter last, Pred pred)
{
  while (first!=last) {
    while (pred(*first)) {
      ++first;
      if (first==last) return first;
    }
    do {
      --last;
      if (first==last) return first;
    } while (!pred(*last));
    std::swap (*first,*last);
    ++first;
  }
  return first;
}

// Unary predicate used for testing.
bool predicate(int n) {
    return n < 0;
}


int main() {
    // Test partition.
    static const int arr[] = {10, 2, 4};
    vector<int> test (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    vector<int>::iterator iter = ::partition(
        test.begin(), test.end(), predicate);
    mycopy(iter, test.end(), std::ostream_iterator<int>(std::cout, " "));
}
       


