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
            char btype;
            
            string filename;
            cout << "\nInput file name with new game: ";
            cin >> filename;
            
            inFile.open(filename);
            if (!inFile){
                inFile.close();
                throw fileNotOpening(filename);
            }else cout << "File: " << filename << " opened.\n";
            inFile.get(btype);
            //cout << "btype: " << btype << endl;
            if ( btype == 't') gameBoard = new Board(filename.c_str());
            else if (btype == 'd') gameBoard = (Board*)new diagBoard(filename.c_str(), 29);
            else throw badGameBoard(filename);
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
                //cout << "input: " << input << endl;
                row = int(input[0] - '0');
                col = int(input[1] - '0');
                val = char(input[2]);
                //cout << "   "<<row << "   "<<col << "   "<<int(val - '0') << endl;
                //if(row < 1 || row > 9) cout << "row issue\n";
                //if(col < 1 || col > 9) cout << "col issue\n";
                //if(sizeof(input) != 3) cout << "size of issue\n" << sizeof(input)/8;
                //if(int(val - '0')> 9) cout << "val issue\n" << int(val-'0') << endl;

                if(row < 1 || row > 9 || col < 1 || col > 9 || int(val - '0')< 1
                   || int(val - '0')> 9 || sizeof(input)/8 != 3){
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
