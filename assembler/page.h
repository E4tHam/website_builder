// page.h

#ifndef PAGE_H
#define PAGE_H

#include <string>
#include "helperClasses.h"

class Page {
    public:
        Page();
        Page( std::string title, std::string srcPath, std::string desPath, Subpage * subpages, unsigned char num_subpages );
        ~Page();
        void build();

    private:
        std::string title, srcPath, desPath;
        Subpage * subpages;
        unsigned char num_subpages;
};

#endif
