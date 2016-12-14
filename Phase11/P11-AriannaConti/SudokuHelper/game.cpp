//
//  game.cpp
//  SudokuHelper
//
//  Created by Arianna on 11/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "game.hpp"


//------------------------------------------------------------------------------
//RUN
void
Game::run(){
    //Create new game
    newGame();
    
    //Set up stacks
    BoardState* b = new BoardState(gameBoard);
    undoStack.push( b );
    redoStack.zap();
    
    //Menu for user
    for(;;){
        Viewer fancyView( 9, 9, *gameBoard);
        char choice = menu_c(title, menuChoices, options, cstring);
        if (gameBoard->isDone()) break;
        switch(choice){
            case 'p':
                //cout << *gameBoard;
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
                save();
                break;
            case 'l':
                load();
                break;
            case 'n':
                newGame();
                break;
            case 'q':
                cout << "Game over.";
                return;
            default:
                cout << "In default of switch statement";
                break;
        }
    }
}

//------------------------------------------------------------------------------
//NEW GAME: open file and create game board
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

//------------------------------------------------------------------------------
//MOVE : check input, make move, update stack
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
    catch (badG& bg){ bg.print(); }
}

//------------------------------------------------------------------------------
//REDO
void Game::redo(){
    if(redoStack.size() == 0) return;
    undoStack.push(redoStack.top());
    redoStack.pop();
    gameBoard->restoreState(undoStack.top());
}

//------------------------------------------------------------------------------
//UNDO
void Game::undo(){
    if (undoStack.size() >= 2){
        redoStack.push(undoStack.top());
        undoStack.pop();
        gameBoard->restoreState(undoStack.top());
    }
}

//------------------------------------------------------------------------------
//SAVE
void Game::save(){
    for(;;){
        try{
            string oFileName;
            cout << "Input an output file name: ";
            cin >> oFileName;
            ofstream outputFile( oFileName, ios::binary );
            if (!outputFile) throw fileNotOpening(oFileName);
            undoStack.top()->serialize(outputFile);
            break;
        }
        catch (badStream& bs) { bs.print(); }
    }
}

//------------------------------------------------------------------------------
//LOAD
void Game::load(){
    for(;;){
        try{
            string iFileName;
            cout << "Input an old game's file name: ";
            cin >> iFileName;
            ifstream inputFile( iFileName, ios::binary );
            if (!inputFile) throw fileNotOpening(iFileName);
            undoStack.zap();
            redoStack.zap();
            BoardState* b = new BoardState(gameBoard);
            undoStack.push( b );
            undoStack.top()->realize(inputFile);
            gameBoard->restoreState(undoStack.top());
            break;
        }
        catch (badStream& bs) { bs.print(); }
    }
}
