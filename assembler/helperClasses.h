#ifndef HELPERCLASSES_H
#define HELPERCLASSES_H

#include <string>

struct Subpage {
    Subpage() { }
    Subpage( std::string path ) { this->path = path; }
    std::string path;
};

#endif
