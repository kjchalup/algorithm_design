// Test a mimic of the list class.
#include <iterator>
#include <iostream>
#include "lst.h"

int main() {
    Lst<int> ll;
    int u1(10);
    int u2(11);
    ll.append(u1);
    ll.append(u2);

    Lst<int> lll;
    int v1(1);
    int v2(2);
    lll.append(v1);
    lll.append(v2);

    lll.insert(ll.begin(), ll.end(), lll.begin());

    std::copy(lll.begin(), lll.end(),
        std::ostream_iterator<int>(std::cout, " "));
}

