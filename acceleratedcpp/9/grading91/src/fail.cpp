// Split a list of students into failing and passing lists.
#include <algorithm>
#include "fail.h"
#include "grade.h"


// Return an vector containig students for whom `decide` is false.
data classify(const data students, bool reject(const Student_info&))
{
    data failing;
    std::remove_copy_if(students.begin(), students.end(),
        back_inserter(failing), reject);
    return failing;
}


// Check whether a student has a failing grade.
bool fgrade(const Student_info& s){
    return s.grade() < 60;
}


// Check whether a student has a passing grade.
bool pgrade(const Student_info& s){
    return !fgrade(s);
}


// Return all the students with failing grades.
data extract_fails(data& students)
{
    data fail = classify(students, pgrade);
    students = classify(students, fgrade);
    return fail;
}
