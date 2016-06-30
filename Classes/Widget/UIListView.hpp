//
//  UIListView.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/27.
//
//

#ifndef UIListView_hpp
#define UIListView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class UIListView : public ListView{
public:
    static UIListView* create();
    
    virtual void onTouchMoved(Touch *touch, Event *unusedEvent);
};

#endif /* UIListView_hpp */
