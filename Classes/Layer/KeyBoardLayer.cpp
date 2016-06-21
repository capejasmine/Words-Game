//
//  KeyBoardLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/21.
//
//

#include "KeyBoardLayer.hpp"

KeyBoardLayer*  KeyBoardLayer::create(){
    KeyBoardLayer *board = new (std::nothrow) KeyBoardLayer();
    if (board && board->init())
    {
        board->autorelease();
        return board;
    }
    CC_SAFE_DELETE(board);
    return nullptr;
}

bool KeyBoardLayer::init(){
    if (!BaseLayer::initWithFile("")) {
        return false;
    }
    
    return true;
}