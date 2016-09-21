//
//  State.cpp
//  SudokuHelper
//
//  Created by Arianna on 9/21/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "State.hpp"

//-------------------------------------------------------------------------
//State Constructor
State::State(char value){
    v = value;
    p = (value == '-') ? 0x23e : 0x0f2 ;//ox3fe
    f = (value == '-') ? false : true ;
}


//-------------------------------------------------------------------------
//Move
void State::move(char ch){
    if( f == true ) say( "Err: This State is fixed.");
    else{
        v = ch;
        p = 0;
    }
}
//-------------------------------------------------------------------------
//Delete
void State::erase(){
    if( f == true ) say( "Err: This State is fixed.");    //otherwise:
    else v = '-';
}
//-------------------------------------------------------------------------
//Print
ostream& State::print( ostream& out){
    for( int k = 1; k <= 9; ++k ){
        char value = v >> 1;
        int x = value & 1;
        if( x == 1 ) cout << k;
    }
    cout << "\n";
    
    
    return out;
}
