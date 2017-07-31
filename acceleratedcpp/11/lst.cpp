// Test a mimic of the list class.
#include <iostream>
#include "lst.h"

int main() {
    Lst<int> lll;
    int v1(1);
    int v2(2);
    int v3(3);
    lll.append(v1);
    lll.append(v2);
    lll.append(v3);
    lll.prepend(v1);
    for (Lst<int>::iterator it = lll.begin(); it != lll.end(); ++it)
        std::cout << *it << " ";

}

