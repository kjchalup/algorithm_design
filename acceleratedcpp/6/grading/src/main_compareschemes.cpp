// Compare how various grading schemes deal with students
// who hadn't turned all their homework in.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::ostream;
using std::endl;
using std::string;


void write_analysis(ostream& out, const string& name,
    double grade_f(const Student_info&),
    const data& did,
    const data& didnt)
{
    out << name << ": median(did) = " << analysis(did, grade_f) <<
        ", median(didnt) = " << analysis(didnt, grade_f) << endl;
}


int main()
{
    // Students who did and didn't do all their homework.
    data did, didnt;

    // Read the student records and partition.
    Student_info student;
    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // Verify that the analyses will show something.
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // Do the analysis.
    write_analysis(cout, "median", median_grade, did, didnt);
    write_analysis(cout, "optimedian", optimedian_grade, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
}
