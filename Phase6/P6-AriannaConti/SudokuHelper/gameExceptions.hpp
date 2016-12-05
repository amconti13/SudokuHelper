//
//  gameExceptions.hpp
//  SudokuHelper
//
//  Created by Arianna on 12/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef gameExceptions_hpp
#define gameExceptions_hpp


class badG {
public:
    string input;
    badG( string input ) : input( input ) {};
    ~badG() = default;
    
    virtual void print() = 0;
    void pr(){
        cerr <<"Input Error. You entered "<< input << endl;
    }
};

class fixedValue : public badG {
public:
    fixedValue( string input ) : badG( input ) { };
    
    void print() {
        cerr << "Value" << input[2] << "is fixed.\n";
        pr();
    }
};

class badInput : public badG{
public:
    badInput( string input ) : badG( input ) { };
    
    void print() {
        cerr << "Either value, or coordinates are invalid "
        << "or there is a number already in this spot.\n";
        pr();
    }
    
};




#endif /* gameExceptions_hpp */
