#ifndef GUARD_ANALYSIS
#define GUARD_ANALYSIS
#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"

bool did_all_hw(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double grade_aux(const Student_info&);
void write_analysis(std::ostream&, const std::string&,
    double (*)(const std::vector<Student_info>&),
    const std::vector<Student_info>&,
    const std::vector<Student_info>&);
#endif
