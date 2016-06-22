//
//  KeyBoardLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/21.
//
//

#include "KeyBoardLayer.hpp"

string g_keyName[] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m","backspace"};

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
    if (!BaseLayer::initWithFile("studio/UI/keyBord/keyBord.json")) {
        return false;
    }
    for (auto s : g_keyName) {
        auto btn = (Button*)(Helper::seekWidgetByName(m_pRootNode, s));
        btn->addTouchEventListener(CC_CALLBACK_2(KeyBoardLayer::keyBoardTouchEvent, this));
    }
    
    for(int i = 1; i < 4; i++){
        auto widget = Helper::seekWidgetByName(m_pRootNode, to_string(i));
        widget->setVisible(false);
        m_arrPos[i-1] = widget->getPosition();
    }
    
    return true;
}

void KeyBoardLayer::keyBoardTouchEvent(Ref* ref, Widget::TouchEventType type) {
    if (Widget::TouchEventType::ENDED != type) {
        return;
    }
    auto target = static_cast<Widget*>(ref);
    string name = target->getName();
    if (m_clickEvent) {
        m_clickEvent(name);
    }
}

void KeyBoardLayer::showFromBottom() {
    if(!m_bIsShow){
        for(int i = 1; i < 4; i++){
            auto widget = Helper::seekWidgetByName(m_pRootNode, to_string(i));
            widget->runAction(Sequence::create(
                                               MoveTo::create(0.01, m_arrPos[i-1] - Vec2(0, 230)),
                                               DelayTime::create(0.2),
                                               CallFunc::create([=](){
                widget->setVisible(true);
            }), DelayTime::create(m_delayT),   MoveTo::create(0.25, m_arrPos[i-1]),NULL));
            m_delayT += 0.08;
        }
        m_delayT = 0.1;
        m_bIsShow = true;
    }
}

void KeyBoardLayer::hideToBottom() {
    if(m_bIsShow){
        for(int i = 3; i > 0; i--){
            auto widget = Helper::seekWidgetByName(m_pRootNode, to_string(i));
            widget->runAction(Sequence::create(DelayTime::create(m_delayT),
                                               MoveTo::create(0.25, m_arrPos[i - 1] - Vec2(0, 230)),
                                               CallFunc::create([=](){
                widget->setVisible(false);
            }),NULL));
            m_delayT += 0.08;
        }
        m_delayT = 0.1;
        m_bIsShow = false;
    }
}

