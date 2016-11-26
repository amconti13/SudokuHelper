//
//  State.cpp
//  SudokuHelper
//
//  Created by Arianna on 9/18/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "State.hpp"
#include "Cluster.hpp"

//STATE-------------------------------------------------------------------------
//Constructor
State::State( char value ) {
    v = value;
    p = (value == '-') ? 0x3fe : 0 ;//001000111110 == 12345---9
    f = (value != '-');
}

//MOVE--------------------------------------------------------------------------
void State::move ( char ch ) {
    if( f ) say( "Err: This State is fixed.");
    else{
        v = ch;
        p = 0;
    }
}

//ERASE-------------------------------------------------------------------------
void State::erase() {
    if( f ) say( "Err: This State is fixed.");    //otherwise:
    else v = '-';
}

//PRINT STATE-------------------------------------------------------------------
ostream& State::print( ostream& out ) {
    for( int k = 1; k <= 9; ++k ) { ((p >> k) & 1) ? cout << k : cout << '-' ; }
    out << "\n";
    return out;
}


//------------------------------------------------------------------------------
//SQUARE------------------------------------------------------------------------
//CONSTRUCT an empty square
Square::Square() : State( '-' ), r(1), c(1) {
    //cout << "Constructing empty Square[" << r << ", " << c << "]" << endl;
}

//------------------------------------------------------------------------------
//INITIALIZE the state of a square
Square::Square ( char ch,  short row, short column ) :
                State( ch ), r( row ), c( column ) {
    //cout << "Constructing Square[" << row << ", " << column << "]" << endl;
}

//DESTRUTOR---------------------------------------------------------------------
Square::~Square() { /*cout << "Deleting square..." << endl;*/ }

//PRINT SQUARE------------------------------------------------------------------
ostream& Square::print( ostream& out ) {
    out << "Square: [" << r <<", "<< c << "]   Value: " << v << "   Possible: ";
    State::print(out);
    return out;
}

//MOVE--------------------------------------------------------------------------
//putting in a char and then looping through clusters in the vector and shooping
void Square::move( char ch ) {
    if ( (v == '-') && ( (p >> (ch - '0')) & 1) ) {  //valid
        for (Cluster* cl: clues) cl->shoop(ch);
        v = ch;
    } else for (Cluster* cl: clues) cl->shoop(v);
}
 
//TURNOFF-----------------------------------------------------------------------
void Square::turnOff( int n ) {
    if((p >> n) & 1) possCount--;
    p &= ~(1 << n);
}
