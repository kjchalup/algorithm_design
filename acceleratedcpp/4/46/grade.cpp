#include "grade.h"
double grade(double mid, double fin, double hw)
{
    return .2 * mid + .4 * fin + .4 * hw;
}

double grade(const Student_info& stud)
{
    return grade(stud.midterm, stud.final, stud.homework);
}
