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
    double analysis(const data&), const data& did, const data& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
        ", median(didnt) = " << analysis(didnt) << endl;
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
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    //write_analysis(cout, "optimistic median",
    //    optimistic_median_analysis, did, didnt);
}
