#ifndef GUARD_ITERTYPE
#define GUARD_ITERTYPE

// Set DATAISLIST to 1 or 0, depending on which container you want to use
// to store the list of students.
#define DATAISLIST 0
#include <list>
#include <vector>
#include "Student_info.h"

#if DATAISLIST == 1
    typedef std::list<Student_info> data;
#else
    typedef std::vector<Student_info> data;
#endif
    

#endif
