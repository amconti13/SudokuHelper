//
//  BoardState.cpp
//  SudokuHelper
//
//  Created by Arianna on 12/13/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "BoardState.hpp"
/*
 Define a new class, BoardState to be an array of 81 States. The BoardState constructor should receive a const Board* or const Board& parameter and copy the State portion of each of the 81 Squares into the new object.
 Define the subscript function for this class to do the normal thing, no bounds-check needed. -> so sub()?*/

BoardState::BoardState( Board* bp ) {
    for(int x = 0; x < 81; ++x){
        //states[x] = (*bp)[x];
        states[x] = (*bp)[x];
    }
    //copy the State portion of each of the 81 Squares into the new object.
}
