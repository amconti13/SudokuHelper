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
    ifstream inFile;
    Board* gameBoard = nullptr;
    const char* title = "Sudoku";
    const int menuChoices = 8;
    const char* options[8] = {
        "print board",
        "move",
        "undo",
        "redo",
        "save game",
        "load game",
        "new game",
        "quit and discard game"
    };
    const string cstring = "pmurslnq";
public:
    Game() = default;
    void run();
    void newGame();
    
    
};


#endif /* game_hpp */
