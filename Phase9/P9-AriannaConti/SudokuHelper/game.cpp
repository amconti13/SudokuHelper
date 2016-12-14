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

    newGame();
    
    BoardState* b = new BoardState(gameBoard);
    undoStack.push( b );
    redoStack.zap();
    
    for(;;){
        
        //
        Viewer fancyView( 9, 9, *gameBoard);
        char choice = menu_c(title, menuChoices, options, cstring);
        if (gameBoard->isDone()) break;
        
        switch(choice){
            case 'p':
                cout << *gameBoard;
                fancyView.show(cout);
                break;
            case 'm':
                move();
                break;
            case 'u':
                undo();
                break;
            case 'r':
                redo();
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
//Create a new BoardState object, initialized to the state after the move. • Push the pointer onto the undo stack.
//Clear the redo stack.

void Game::move() throw (badGameBoard){
    string input;
    int row = 0, col = 0;
    char val = '0';
    
    try{
        cout << "Enter row, column and value(rcv): ";
        cin >> input;
        row = int(input[0] - '0');
        col = int(input[1] - '0');
        val = char(input[2]);
        
        if(row < 1 || row > 9 || col < 1 || col > 9 || int(val - '0')< 1
           || int(val - '0')> 9 || sizeof(input)/8 != 3){
            throw badInput(input);
        }
        gameBoard->move( row, col, val);
        BoardState* b = new BoardState(gameBoard);
        undoStack.push( b );
        redoStack.zap();
    }
    catch (badG& bg){
        bg.print();
    }
}
//Activate menu options undo and redo. Also instantiate two stacks of BoardState*s: the undo stack and the redo stack. Use the Stack class defined below, which is adapted from the stl Stack template. The undo stack always holds a copy of the current state of the game. The redo stack holds states that have been undone, until they are ready to be redone. The Game class has custody of these dynamically allocated objects and is responsible for deallocating them whenever one is discarded.

void Game::redo(){
    if(redoStack.size() == 0) return;
    undoStack.push(redoStack.top());
    redoStack.pop();
    gameBoard->restoreState(undoStack.top());
        
    
}

void Game::undo(){
    if (undoStack.size() >= 2){
        redoStack.push(undoStack.top());
        undoStack.pop();
        gameBoard->restoreState(undoStack.top());
    }
    
}
