//
//  State.cpp
//  SudokuHelper
//
//  Created by Arianna on 9/18/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "State.hpp"

//-------------------------------------------------------------------------
//State Constructor
State::State( char value ) {
    v = value;
    p = (value == '-') ? 0x23e : 0x0f2 ;//ox3fe
    //001000111110 == 12345---9 : 000011110010 == 1--4567--
    f = (value == '-') ? false : true ;
}

//-------------------------------------------------------------------------
//Move
void State::move ( char ch ) {
    if( f == true ) say( "Err: This State is fixed.");
    else{
        v = ch;
        p = 0;
    }
}

//-------------------------------------------------------------------------
//Delete
void State::erase() {
    if( f == true ) say( "Err: This State is fixed.");    //otherwise:
    else v = '-';
}

//-------------------------------------------------------------------------
//Print
ostream& State::print( ostream& out ) {
    for( int k = 1; k <= 9; ++k ) { ((p >> k) & 1) ? cout << k : cout << '-' ; }
    //cout << "\n";
    return out;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Construct an empty square
Square::Square() : State( '-' ) {
    r = 1;
    c = 1;
    cout << "Constructing empty Square[" << r << ", " << c << "]" << endl;
}

//-------------------------------------------------------------------------
//Initialize the state of a square
Square::Square ( char ch,  short row, short column ) : State( ch ) {
    cout << "Constructing Square[" << row << ", " << column << "]" << endl;
    r = row;
    c = column;
}

//-------------------------------------------------------------------------
//Destructor
Square::~Square() {
    cout << "Deleting square..." << endl;
}

//----------------------------------------------------------------------------
//Print
ostream& Square::print( ostream& out ){
    out << "Square [" << r << ", " << c << "]   ";
    out << "Value: " << v << "   Possible: ";
    
    State::print(out);
    out << "    Fixed: " << (f ? "True" : "False");
    out << "\n";
    return out;
}













