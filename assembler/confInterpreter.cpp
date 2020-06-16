#include "confInterpreter.h"
#include <iostream>

using namespace std;

ConfInterpreter::ConfInterpreter() {
    
    ifstream ifs( "website.conf" );
    string line;

    while (line.substr(0,7) != "website") getline( ifs, line );
    name = getQuoteContents(line);
    while (line.substr(0,6) != "domain") getline( ifs, line );
    domain = getQuoteContents(line);
    while (line.substr(0,9) != "num_pages") getline( ifs, line );
    num_pages = (unsigned char) stoi( line.substr( line.find_last_not_of("0123456789") ) );
    while (line.substr(0,7) != "srcPath") getline( ifs, line );
    srcPath = getQuoteContents(line);
    while (line.substr(0,12) != "subpagesPath") getline( ifs, line );
    subpagesPath = getQuoteContents(line);
    while (line.substr(0,9) != "buildPath") getline( ifs, line );
    buildPath = getQuoteContents(line);

    page_confs = new pageConf[ num_pages ];
    
    for ( unsigned char i = 0; i < num_pages; i++ ) {
        while (line.substr(0,4) != "page") getline( ifs, line );
        page_confs[i].name = getQuoteContents(line);
        while (line.substr(0,5) != "title") getline( ifs, line );
        page_confs[i].title = getQuoteContents(line);
        while (line.substr(0,7) != "srcPath") getline( ifs, line );
        page_confs[i].srcPath = getQuoteContents(line);
        while (line.substr(0,7) != "desPath") getline( ifs, line );
        page_confs[i].desPath = getQuoteContents(line);
        while (line.substr(0,5) != "chain") getline( ifs, line );

        getline( ifs, line );
        while (line.substr(0,1) != "}") {
            page_confs[i].chain.push_back( getQuoteContents(line) );
            getline( ifs, line );
        }

    }


}
ConfInterpreter::~ConfInterpreter() {
    delete [] page_confs;
}
string getQuoteContents( const string & line ) {
    string out = line.substr( line.find('\"')+1 );
    out = out.substr( 0, out.find('\"') );
    // cout << "result: " << out << endl;
    return out;
}
