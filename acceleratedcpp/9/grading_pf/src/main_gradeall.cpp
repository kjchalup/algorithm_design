// Output grades of all students, separating failed students out.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::partition;

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
    
    // Partition the students into passing / failing.
    data::iterator first_fail = partition(
        students.begin(), students.end(), ispassing);
    sort(students.begin(), first_fail, compare);
    sort(first_fail, students.end(), compare);

    // Print out passing students.
    cout << "PASSING STUDENTS: " << endl;
    for (data::const_iterator it = students.begin();
        it != first_fail; ++it) {
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        cout << endl;
    }

    // Print out failed students.
    cout << endl << "FAILING STUDENTS: " << endl;
    for (data::const_iterator it = first_fail;
        it != students.end(); ++it)
        cout << it->name() << endl;

    return 0;
}
