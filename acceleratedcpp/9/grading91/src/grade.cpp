// Grading schemes and their analysis functions.
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <vector>
#include "grade.h"

using std::vector;

double grade(double mid, double fin, double hw)
{
    return .2 * mid + .4 * fin + .4 * hw;
}


// Compute the average grade.
double average(const vector<double>& v)
{
    if (v.size() == 0) 
        throw std::domain_error("average of an empty vector");
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}


// Compute the median grade. Note: this changes the input vector.
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
