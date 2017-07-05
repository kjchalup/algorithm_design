// A product program.
#include <iostream>

int main()
{
    int product = 1;
    for (int i = 1; i != 11; i++)
        product *= i;
    std::cout << product << std::endl;
    return 0;
}
