//
//  BoardState.hpp
//  SudokuHelper
//
//  Created by Arianna on 12/13/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef BoardState_hpp
#define BoardState_hpp

#include "Board.hpp"

class BoardState{
private:
    State states[81];
public:
    BoardState( Board* bp );//, const Board& br
    ~BoardState() = default;
    inline State operator [] (int x) {return states[x];}
    void serialize( ofstream& gameOut );
    void realize( ifstream& gameIn );
    
};

#endif /* BoardState_hpp */
