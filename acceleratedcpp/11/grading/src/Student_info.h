#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info {
    public:
        // Create constructors.
        Student_info();
        Student_info(std::istream&);

        // Copy constructor.
        Student_info(const Student_info&);

        // Assign constructor.
        Student_info& operator=(const Student_info&);

        // Destructor.
        ~Student_info();

        std::string name() const;
        bool valid() const;
        std::istream& read(std::istream&);
        double grade() const;
        std::string letter_grade() const;
        static int n_create, n_copy, n_assign, n_destruct;
    private:
        void clear();
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};


typedef std::vector<Student_info> data;


bool compare(const Student_info&, const Student_info&);
#endif
