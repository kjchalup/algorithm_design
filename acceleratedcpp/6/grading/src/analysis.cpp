#include <algorithm>
#include "analysis.h"

using std::vector;
using std::string;

bool did_all_hw(const Student_info& stud)
{
    return find(stud.homework.begin(), stud.homework.end(), 0)
        == stud.homework.end();
}
