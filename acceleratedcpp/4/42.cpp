#include <math.h>
#include <iomanip>
#include <iostream>

int main()
{
    for (int num = 0; num != 101; ++num)
        std::cout << std::setw(4) << num << " " << pow(num, 2) << std::endl;
    return 0;
}
