// Split a list of students into failing and passing lists.
#include "fail.h"
#include "grade.h"

using std::list;

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

data extract_fails(data& students)
{
    data fail;
    data::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}
