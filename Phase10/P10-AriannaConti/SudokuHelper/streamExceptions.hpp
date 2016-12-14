//
//  streamExceptions.h
//  SudokuHelper
//
//  Created by Arianna on 12/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef streamExceptions_h
#define streamExceptions_h

class badStream{
public:
    string fileName;
    
    badStream( string fileName ) : fileName( fileName ) {};
    ~badStream() = default;
    
    virtual void print() = 0;
    void pr(){
        cerr <<"  You entered "<< fileName << endl;
    }
};


class fileNotOpening : public badStream {
public:
    fileNotOpening( string fileName ) : badStream( fileName ) {};

    void print() {
        cerr << "File not opening...\n";
        pr();
    }
};

class notNewLine : public badStream {
public:
    notNewLine( string fileName ) : badStream( fileName ) {};
    
    void print() {
        cerr << "Not a new line...\n";
        pr();
    }
    
};

class endOfFileErr : public badStream{
public:
    endOfFileErr( string fileName ) : badStream( fileName ) {};
    
    void print() {
        cerr << "end of file error...\n";
        pr();
    }
    
};








#endif /* streamExceptions_h */
