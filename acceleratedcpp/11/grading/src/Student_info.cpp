// Student data structure.
#include "Student_info.h"
#include "grade.h"
#include <string>
#include <iostream>
#include <vector>

using std::istream;
using std::string;
using std::vector;

int Student_info::n_create = 0;
int Student_info::n_copy = 0;
int Student_info::n_assign = 0;
int Student_info::n_destruct = 0;



// Set exam grades to 0 and hw grades to empty vector.
// Update the creation counter.
Student_info::Student_info(): midterm(0), final(0) { n_create++; };


// Initiate by reading grades from input stream (see Student_info::read).
Student_info::Student_info(istream& in) { read(in); n_create++; };

// Copy constructor.
Student_info::Student_info(const Student_info& s) {
    n_copy++;
    n = s.n;
    midterm = s.midterm;
    final = s.final;
    homework = std::vector<double>(s.homework.begin(), s.homework.end());
}


// Clear memory.
void Student_info::clear() {
    homework.clear();
}

// Assignment constructor.
Student_info& Student_info::operator=(const Student_info& s) {
    // If self-assigning, do nothing.
    n_assign++;
    if (&s != this) {
        clear();
        homework = std::vector<double>(
            s.homework.begin(), s.homework.end());
        n = s.n;
        midterm = s.midterm;
        final = s.final;
    }
    return *this;
}

// Destructor.
Student_info::~Student_info() {
    n_destruct++;
    homework.clear();
}


// Return student's name.
std::string Student_info::name() const { return n; };


// Check whether the student did any homework.
bool Student_info::valid() const { return !homework.empty(); };


// Read grades from an input stream. The format of a line should be
// student_name midterm_grade final_grade hw_1_grade, ..., hw_n_grade
istream& Student_info::read(istream& is)
{
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
    return is;
}


// Grade a student, averaging hw results.
double Student_info::grade() const {
    return ::grade(midterm, final, average(homework));
} 

string Student_info::letter_grade() const {
    // Letter grade array.
    static const string grades[] = {"A+", "A", "A-", "B+", "B", "B-",
        "C+", "C", "C-", "D", "F"};
    static const double gradelims[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const size_t n_grades = sizeof(gradelims) / sizeof(*gradelims);
    for (size_t i = 0; i != n_grades; ++i)
        if (gradelims[i] < grade())
            return grades[i];
    return "?";
}


// Order students by name.
bool compare(const Student_info& stud1, const Student_info& stud2)
{
    return stud1.name() < stud2.name();
}
