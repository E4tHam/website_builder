#include "page.h"
#include <fstream>
#include <iostream>

using namespace std;

Page::Page() {
    throw this;
}
Page::Page( string title, string srcPath, string desPath, Subpage * subpages, unsigned char num_subpages ) {
    this->title = title;
    this->srcPath = srcPath;
    this->desPath = desPath;
    this->subpages = subpages;
    this->num_subpages = num_subpages;
}
Page::~Page() {
    delete [] subpages;
}

void Page::build() {

    ofstream ofs( desPath );

    if ( !ofs.is_open() ) { cerr << "Failed to create file " << desPath << endl; return; }

    ifstream ifs;
    string line;

    for ( unsigned char i = 0; i < num_subpages; i++ ) {
        ifs.open( "pages/" + srcPath + "/" + subpages[i].path );
        if ( !ifs.is_open() ) ifs.open( "subpages/" + subpages[i].path );
        if ( !ifs.is_open() ) { cerr << "Failed to find " + srcPath + "/" + subpages[i].path << endl; continue; }

        ofs << "// " << subpages[i].path << endl;

        while ( ifs.good() ) {
            getline( ifs, line );
            ofs << line << endl;
        }

        ofs << endl;

        ifs.close();

    }
    ofs.close();
    cout << "Successfully created file " << desPath << endl;

}
