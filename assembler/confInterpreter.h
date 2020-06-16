#ifndef CONFINTERPRETER_H
#define CONFINTERPRETER_H

#include <fstream>
#include <vector>
#include <string>

struct pageConf {
    std::string name, title, srcPath, desPath;
    std::vector<std::string> chain;
};

class ConfInterpreter {
    public:
        ConfInterpreter();
        ~ConfInterpreter();
        
        std::string name, domain, srcPath, subpagesPath, buildPath;
        unsigned char num_pages;
        pageConf * page_confs;
};

std::string getQuoteContents( const std::string & line );

#endif
