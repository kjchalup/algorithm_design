// Student data structure.
#include "Student_info.h"
#include "grade.h"
#include <string>
#include <iostream>
#include <vector>

using std::istream;
using std::string;
using std::vector;


// Set exam grades to 0 and hw grades to empty vector.
Student_info::Student_info(): pass(false) { };


// Initiate by reading grades from input stream (see Student_info::read).
Student_info::Student_info(istream& in) { read(in); };


// Return student's name.
std::string Student_info::name() const { return n; };


// Read grades from an input stream. The format of a line should be
// student_name midterm_grade final_grade hw_1_grade, ..., hw_n_grade
istream& Student_info::read(istream& is)
{
    vector<double> homework;
    float midterm, final;
    // Read in single-number scores.
    is >> n >> midterm >> final;
    
    // Read in a variable-length hw score vector.
    if (is) {
        // Get rid of previous content.
        is.clear();

        // Read homework grades.
        double grade;
        while(is >> grade)
            homework.push_back(grade);

        // Discard any remaining content.
        is.clear();
    }
    if (homework.size() > 0)
        pass = ::grade(midterm, final, average(homework)) > 60 ? true : false;
    else
        pass = false;
    return is;
}


// Grade a student, averaging hw results.
double Student_info::passes() const {
    return pass;
} 


// Order students by name.
bool compare(const Student_info& stud1, const Student_info& stud2)
{
    return stud1.name() < stud2.name();
}

// Check whether a student passes.
bool ispassing(const Student_info& s) {
    return s.passes();
}
