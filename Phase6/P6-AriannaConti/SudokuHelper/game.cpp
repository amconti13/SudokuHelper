//
//  game.cpp
//  SudokuHelper
//
//  Created by Arianna on 11/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "game.hpp"

void
Game::newGame(){
    for(;;){
        try{
            string filename;
            cout << "\nInput file name with new game: ";
            cin >> filename;
            gameBoard = new Board(filename.c_str());
            break;
        }
        catch(badStream& bs){
            bs.print();
        }
    }
}

void
Game::run(){
    string input;
    int row = 0, col = 0;
    char val = '0';
    
    newGame();
    
    for(;;){
        
        
        char choice = menu_c(title, menuChoices, options, cstring);
        if (gameBoard->isDone()) break;
        
        switch(choice){
        case 'p':
            cout << *gameBoard;
            break;
        case 'm':
            try{
                cout << "Enter row, column and value(rcv): ";
                cin >> input;
                row = int(input[0] - '0');
                col = int(input[1] - '0');
                val = char(input[2]);
                //cout << "   "<<row << "   "<<col << "   "<<int(val - '0');
                if( row < 1 || row > 9 || col < 1 || col > 9
                   || int(val - '0')< 1 || int(val - '0')> 9 || sizeof(input) != 3)
                   {
                    throw badInput(input);
                }
                gameBoard->move( row, col, val);
            }
            catch (badG& bg){
                bg.print();
            }
            break;
        case 'u':
            break;
        case 'r':
            break;
        case 's':
            break;
        case 'l':
            break;
        case 'n':
            newGame();
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
