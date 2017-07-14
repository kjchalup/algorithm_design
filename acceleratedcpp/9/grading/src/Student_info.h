#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info {
    public:
        Student_info();
        Student_info(std::istream&);
        std::string name() const;
        bool valid() const;
        std::istream& read(std::istream&);
        double grade() const;
    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};


typedef std::vector<Student_info> data;


bool compare(const Student_info&, const Student_info&);
#endif
