//
//  game.cpp
//  SudokuHelper
//
//  Created by Arianna on 11/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "game.hpp"


Game::Game():gameBoard("sudo-test1.txt"){}


void
Game::run(){
    string input;
    
    
    for(;;){
        cout << gameBoard;
        
        char choice = menu_c(title, menuChoices, options, cstring);
        if (gameBoard.isDone()) break;
        
        switch(choice){
        case 'm':
            cout << "Enter row, column and value(rcv): ";
            cin >> input;
            gameBoard.move(int(input[0] - '0'), int(input[1] - '0'), char(input[2]));
            break;
        case 'u':
            break;
        case 'r':
            break;
        case 's':
            break;
        case 'l':
            break;
        case 'q':
            cout << "Game over.";
            return;
        default:
            cout << "in default of switch statement";
            break;
            
        }
        
        
        
        
        
        
    }
    
    
    
    
}
