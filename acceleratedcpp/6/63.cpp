#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> u(10, 100);
    std::vector<int> v(u.begin(), u.end());
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        std::cout << *it << std::endl;
    }
    //std::copy(u.begin(), u.end(), v.begin());
    return 0;
}

