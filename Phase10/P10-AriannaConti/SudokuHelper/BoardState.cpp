//
//  BoardState.cpp
//  SudokuHelper
//
//  Created by Arianna on 12/13/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "BoardState.hpp"

BoardState::BoardState( Board* bp ) {
    for(int x = 0; x < 81; ++x){
        //states[x] = (*bp)[x];
        states[x] = (*bp)[x];
    }
    //copy the State portion of each of the 81 Squares into the new object.
}

void BoardState::serialize( ofstream& gameOut ){
    gameOut.write((char*)states, (81*sizeof(State)));
    gameOut.close();
}

void BoardState::realize( ifstream& gameIn ){
    gameIn.read((char*)states, (81*sizeof(State)));
}

