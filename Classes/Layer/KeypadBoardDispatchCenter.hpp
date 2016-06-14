//
//  KeypadBoardDispatchCenter.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef KeypadBoardDispatchCenter_hpp
#define KeypadBoardDispatchCenter_hpp

#include "cocos2d.h"
#include "SingleT.hpp"

USING_NS_CC;

class KeypadDelegate{
public:
    virtual bool keybackKeyDown();
};

class KeypadBoardDispatchCenter : Ref, SingleT<KeypadBoardDispatchCenter>{
public:
    KeypadBoardDispatchCenter();
    
    void KeyBackClicked();
    
    void addDelegate(Ref* del);
    
    void removeDelegate(Ref* del);
private:
    Vector<Ref*> m_vDelegate;
    
    EventListenerKeyboard* m_pKeyBordListener;
};

#endif /* KeypadBoardDispatchCenter_hpp */
