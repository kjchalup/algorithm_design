// Split a list of students into failing and passing lists.
#include <algorithm>
#include "fail.h"
#include "grade.h"
#include "utils.h"

bool fgrade(const Student_info& s){
    return median_grade(s) < 60;
}

bool pgrade(const Student_info& s){
    return !fgrade(s);
}

data extract_fails(data& students)
{
    data fail = classify(students, pgrade);
    students = classify(students, fgrade);
    return fail;
}
