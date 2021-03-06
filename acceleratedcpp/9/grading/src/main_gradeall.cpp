// Output grades of all students, separating failed students out.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "fail.h"
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             

int main()
{
    // Create the students vector.
    data students;
    Student_info record;
    string::size_type maxlen = 0;

    // Read in students data.
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    // Push failing students to a separate vector.
    data failed_students;
    failed_students = extract_fails(students);

    // Sort alphabetically.
    sort(students.begin(), students.end(), compare);

    // Print out grades.
    for (data::const_iterator it = students.begin();
        it != students.end(); ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');

        try {
            streamsize prec = cout.precision();
            cout << setprecision(3) << it->grade() << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    // Print out failed students.
    cout << endl << "FAILED STUDENTS:" << endl;
    for (data::const_iterator it = failed_students.begin();
        it != failed_students.end(); ++it)
        cout << it->name() << endl;

    return 0;
}
