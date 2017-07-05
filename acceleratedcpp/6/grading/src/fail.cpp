// Split a list of students into failing and passing lists.
#include <algorithm>
#include "fail.h"
#include "grade.h"

bool fgrade(const Student_info& s){
    return median_grade(s) < 60;
}

bool pgrade(const Student_info& s){
    return !fgrade(s);
}

// Move failing students from `students` to 
// a new vector `fail`.
data extract_fails(data& students)
{
    data::iterator iter = std::stable_partition(
        students.begin(), students.end(), pgrade);
    data fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}
