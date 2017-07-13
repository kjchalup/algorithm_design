// Binary search with templates.
#include <iostream>
#include <vector>

// Take an input iterator and an object, and
// return the object's location.
template <class Racc, class X>
bool binary_search(Racc begin, Racc end, const X& x) {
    while (begin != end) {
        Racc mid = begin + (end - begin) / 2;
        if (*mid == x) 
            return true;
        if (*mid < x)
            begin = mid + 1;
        else
            end = mid;
    }
    return false;
}


int main() {
    std::vector<int> haystack {1, 3, 4, 5, 9};
    std::cout << "The following calls should return true (1):" << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 1) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 3) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 4) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 5) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 9) << std::endl;
    std::cout << "The following calls should return false (0):" << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 0) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 10) << std::endl;
    std::cout << binary_search(haystack.begin(), haystack.end(), 7) << std::endl;

}

