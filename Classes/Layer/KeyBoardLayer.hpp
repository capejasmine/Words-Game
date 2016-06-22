//
//  KeyBoardLayer.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/21.
//
//

#ifndef KeyBoardLayer_hpp
#define KeyBoardLayer_hpp

#include <stdio.h>
#include "BaseLayer.hpp"

typedef std::function<void(string)> clickEvent;

class KeyBoardLayer : public BaseLayer{
public:
    static KeyBoardLayer* create();
    
    virtual bool init();
    
    void setTouchEvent(clickEvent e){
        m_clickEvent = e;
    }
    
    void keyBoardTouchEvent(Ref* ref, Widget::TouchEventType type);
    
    void showFromBottom();
    
    void hideToBottom();
private:
    
    clickEvent m_clickEvent;
    
    float m_delayT = 0.1;
    
    Vec2 m_arrPos[3];
    
    bool m_bIsShow = false;
};

#endif /* KeyBoardLayer_hpp */
