//
//  UIButtonLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "UIButtonLayer.hpp"


UIButtonLayer* UIButtonLayer::craete(std::string pathName){
    UIButtonLayer* layer = new UIButtonLayer();
    if (layer->init(pathName)) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool UIButtonLayer::init(std::string pathName){
    if(!CBLayer::init()){
        return false;
    }
   
    m_pUiRoot = GUIReader::getInstance()->widgetFromJsonFile(pathName.c_str());
    
    this->setClikcForBtn(m_pUiRoot);
    
    return true;
}

void UIButtonLayer::setClikcForBtn(Node* root){
    for (auto pNode : root->getChildren()) {
        if (pNode) {
            Button* btn = dynamic_cast<Button*>(pNode);
            btn->addTouchEventListener(CC_CALLBACK_2(UIButtonLayer::onClick, this));
        }
    }
}

void UIButtonLayer::onClick(Ref* ref,Widget::TouchEventType type){
    if (Widget::TouchEventType::ENDED != type) {
        return;
    }
    auto btn = static_cast<Button*>(ref);
    std::string name = btn->getName();
    if (name.compare("home")) {
        xGAME->enterHomeScene();
    }
    else if (name.compare("choose")){
        xGAME->enterChooseScene();
    }
    else if (name.compare("music")){
        xAudio->changeMode();
    }
}

