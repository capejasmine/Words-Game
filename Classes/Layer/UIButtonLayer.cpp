//
//  UIButtonLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "UIButtonLayer.hpp"


UIButtonLayer* UIButtonLayer::craete(std::string csbPath){
    UIButtonLayer* layer = new UIButtonLayer();
    if (layer->init(csbPath)) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool UIButtonLayer::init(std::string csbPath){
    if(!CBLayer::init()){
        return false;
    }
    
    
    return true;
}

void UIButtonLayer::onButtonClick(Ref* ref, TouchEventType type){
    if (TouchEventType::TOUCH_EVENT_ENDED != type) {
        return;
    }
    auto btn = static_cast<Button*>(ref);
    std::string name = btn->getName();
    if (name.compare("")) {
        
    }
    else if (name.compare("")){
        
    }
    else if (name.compare("")){
        
    }
}

