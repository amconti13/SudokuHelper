//
//  Board.hpp
//  SudokuHelper
//
//  Created by Arianna on 10/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "State.hpp"

class Board {
private:
    Square bd[81];
    ifstream inFile;
    
public:
    ~Board();
    Board(const char* filename);
    Square& sub(int j, int k);
    ostream& print( ostream& out);
    
};

inline ostream& operator<< (ostream& out, Board& b){
    b.print(out);
    return out;
}









#endif /* Board_hpp */
