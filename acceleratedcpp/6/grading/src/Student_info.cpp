// Student data structure.
#include "Student_info.h"
#include <iostream>
#include <vector>

using std::istream;
using std::vector;

bool compare(const Student_info& stud1, const Student_info& stud2)
{
    return stud1.name < stud2.name;
}

istream& read(istream& is, Student_info& stud)
{
    // Read in single-number scores.
    is >> stud.name >> stud.midterm >> stud.final;
    
    // Read in a variable-length hw score vector.
    read_hw(is, stud.homework);
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // Get rid of previous content.
        in.clear();

        // Read homework grades.
        double grade;
        while(in >> grade)
            hw.push_back(grade);

        // Discard any remaining content.
        in.clear();
    }
    return in;
}
