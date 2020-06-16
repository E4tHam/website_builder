// website.h

#ifndef WEBSITE_H
#define WEBSITE_H

#include <string>

#include "page.h"

class Website {
    public:
        Website();
        ~Website();

        void build();

    private:
        std::string name;
        std::string domain;
        unsigned char num_pages;
        Page ** pages;
        std::string buildPath;
};

#endif
