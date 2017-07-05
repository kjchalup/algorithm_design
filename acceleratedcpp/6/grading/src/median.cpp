// Compute the median of a vector.
#include <algorithm>
#include <stdexcept>
#include <vector>
#include<iostream>

double median(std::vector<double> vec)
{
    if (vec.size() == 0) 
        throw std::domain_error("median of an empty vector");

    std::vector<double>::size_type mid;
    mid = vec.size() / 2;
    std::sort(vec.begin(), vec.end());

    return vec.size() % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 
                               : vec[mid];
}

