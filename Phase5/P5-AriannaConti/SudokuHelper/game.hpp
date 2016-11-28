//
//  game.hpp
//  SudokuHelper
//
//  Created by Arianna on 11/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "board.hpp"

class Game{
private:
    Board gameBoard;
    const char* title = "Sudoku";
    int menuChoices = 6;
    const char* options[6] = {"move", "undo", "redo", "save game", "load game", "quit and discard game"};
    const string cstring = "murslq";
public:
    Game();
    void run();
    
    
};


#endif /* game_hpp */
