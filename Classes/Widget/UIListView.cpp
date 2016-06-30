//
//  UIListView.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/27.
//
//

#include "UIListView.hpp"

UIListView* UIListView::create()
{
    UIListView* widget = new UIListView();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

void UIListView::onTouchMoved(Touch *touch, Event *unusedEvent){
    log("move");
    
    ListView::onTouchMoved(touch, unusedEvent);
}