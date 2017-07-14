// Various utility functions.
#include <algorithm>
#include <iterator>
#include "utils.h"
#include "Student_info.h"

// Return an vector containig students for whom `decide` is false.
data classify(const data students, bool reject(const Student_info&))
{
    data failing;
    std::remove_copy_if(students.begin(), students.end(),
        back_inserter(failing), reject);
    return failing;
}

