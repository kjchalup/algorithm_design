// A container that mimics the stl vector class.
#include <algorithm>
#include <iostream>
#include <iterator>
#include "vec.h"


int main() {
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    v.erase(v.begin() + 2, v.end());
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    v.push_back(5);
    v.erase(v.begin() + 1);
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    v.push_back(6);
    v.clear();
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));
}


