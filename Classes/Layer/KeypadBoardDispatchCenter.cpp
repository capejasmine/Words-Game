//
//  KeypadBoardDispatchCenter.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "KeypadBoardDispatchCenter.hpp"

KeypadBoardDispatchCenter::KeypadBoardDispatchCenter(){
    
    m_pKeyBordListener = EventListenerKeyboard::create();
    m_pKeyBordListener->onKeyReleased = [this](EventKeyboard::KeyCode code, Event*){
        if (EventKeyboard::KeyCode::KEY_BACK == code) {
            KeyBackClicked();
        }
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(m_pKeyBordListener, 1);
}

void KeypadBoardDispatchCenter::KeyBackClicked(){
    for (int i = 0; i < m_vDelegate.size() - 1; i--) {
        KeypadDelegate* delegate = dynamic_cast<KeypadDelegate*>(m_vDelegate.at(i));
        if (delegate) {
            if(delegate->keybackKeyDown()){
                break;
            }
        }
    }
}

void KeypadBoardDispatchCenter::addDelegate(Ref* del){
    m_vDelegate.pushBack(del);
}

void KeypadBoardDispatchCenter::removeDelegate(Ref* del){
    m_vDelegate.eraseObject(del);
}

bool KeypadDelegate::keybackKeyDown(){
    return false;
}