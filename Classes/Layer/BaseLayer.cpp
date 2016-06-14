//
//  BaseLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "BaseLayer.hpp"

bool BaseLayer::initWithFile(std::string pathNmae){
    if (!CBLayer::init()) {
        return false;
    }
    
    m_pRootNode = GUIReader::getInstance()->widgetFromJsonFile(pathNmae.c_str());
    if(m_pRootNode){
        this->addChild(m_pRootNode, kUi);
    }
    
    return true;
}

bool BaseLayer::keybackKeyDown(){
    return false;
}

void BaseLayer::setBackGround(std::string path) {
    if (!m_pBgSprite) {
        m_pBgSprite = Sprite::create(path.c_str());
        m_pBgSprite->setPosition(getContentSize()/2);
        addChild(m_pBgSprite, kBackground);
    }
}
