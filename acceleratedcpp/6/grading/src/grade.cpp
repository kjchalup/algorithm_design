// Grading schemes and their analysis functions.
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

double grade(double mid, double fin, double hw)
{
    return .2 * mid + .4 * fin + .4 * hw;
}


double average(const vector<double>& v)
{
    if (v.size() == 0) 
        throw std::domain_error("median of an empty vector");
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}


double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}


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


double average_analysis(const data& students)
{
    vector<double> grades;

    // Compute average grade of each student.
    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), average_grade);
    return median(grades);
}


double median_grade(const Student_info& s) {
    return grade(s.midterm, s.final, median(s.homework));
}


double median_analysis(const data& students)
{
    vector<double> grades;

    // Compute average grade of each student.
    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), median_grade);
    return median(grades);
}


bool did_all_hw(const Student_info& s)
{
    return find(s.homework.begin(), s.homework.end(), 0.0) == s.homework.end();
}
