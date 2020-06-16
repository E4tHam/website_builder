#include "website.h"
#include "confInterpreter.h"

using namespace std;

Website::Website() {
    ConfInterpreter conf;

    num_pages = conf.num_pages;
    domain = conf.domain;
    buildPath = conf.buildPath;

    pages = new Page*[ num_pages ];
    
    for ( unsigned char i = 0; i < num_pages; i++ ) {
        
        Subpage * subpages = new Subpage[ conf.page_confs[i].chain.size() ];
        for ( unsigned char p = 0; p < conf.page_confs[i].chain.size(); p++ )
            subpages[p] = Subpage( conf.page_confs[i].chain.at(p) );

        pages[i] = new Page (
            conf.page_confs[i].title,
            conf.page_confs[i].srcPath,
            conf.buildPath + "/" + conf.page_confs[i].desPath,
            subpages,
            conf.page_confs[i].chain.size()
        );
    }

}
Website::~Website() {
    for ( unsigned char i = 0; i < num_pages; i++ )
        delete pages[i];
    delete [] pages;
}

void Website::build() {
    for ( unsigned char i = 0; i < num_pages; i++ )
        pages[i]->build();
}
