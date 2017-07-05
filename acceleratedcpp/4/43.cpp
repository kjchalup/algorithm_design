#include <math.h>
#include <iomanip>
#include <iostream>

int main()
{
    int max = 10001;
    int prec = log10(max) + 1;
    for (int num = 0; num != max; ++num)
        std::cout << std::setw(prec) << num << " " << pow(num, 2) << std::endl;
    return 0;
}
