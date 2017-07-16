#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info {
    public:
        Student_info();
        Student_info(std::istream&);
        std::istream& read(std::istream&);
        std::string name() const;
        double passes() const;
    private:
        std::string n;
        bool pass;
};


typedef std::vector<Student_info> data;


bool compare(const Student_info&, const Student_info&);


bool ispassing(const Student_info&);
#endif
