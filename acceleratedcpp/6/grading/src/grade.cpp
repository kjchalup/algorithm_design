#include <vector>
#include "median.h"
#include "grade.h"
double grade(double mid, double fin, double hw)
{
    return .2 * mid + .4 * fin + .4 * hw;
}

double grade(double mid, double fin, std::vector<double> hw){
    return grade(mid, fin, median(hw));
}

double grade(const Student_info& stud)
{
    return grade(stud.midterm, stud.final, stud.homework);
}
