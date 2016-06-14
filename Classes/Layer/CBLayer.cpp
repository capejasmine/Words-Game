//
//  CBLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "CBLayer.hpp"

bool CBLayer::init(){
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CBLayer::init());
        
        m_pBgLayer = Layer::create();
        this->addChild(m_pBgLayer,kBackground);
        
        m_pContentLayer = Layer::create();
        this->addChild(m_pContentLayer, kContent);
        
        m_pUiLayer = Layer::create();
        this->addChild(m_pBgLayer,kUi);
        
        m_pPopLayer = Layer::create();
        this->addChild(m_pPopLayer,kPop);
        
        bRet = true;
    }while (0);
    
    return bRet;
    
}

void CBLayer::addToUiLayer(Node* child, int zoder, int tag){
    
    m_pUiLayer->addChild(child, zoder, tag);
}

void CBLayer::addToContentLayer(Node* child, int zoder, int tag){
    
    m_pContentLayer->addChild(child, zoder, tag);
}

void CBLayer::addToBgLayer(Node* child, int zoder, int tag){

    m_pBgLayer->addChild(child, zoder, tag);
}

void CBLayer::addToPopLayer(Node* child, int zoder, int tag){
    
    m_pPopLayer->addChild(child, zoder, tag);
}