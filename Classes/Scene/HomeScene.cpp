//
//  HomeScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "HomeScene.hpp"

Scene* HomeScene::scene(){
    Scene* scene = Scene::create();
    HomeScene* layer = HomeScene::create();
    scene->addChild(layer);
    return scene;
}

bool HomeScene::init(){
    if (!BaseLayer::initWithFile("")) {
        return false;
        
    }
    
    this->setBackGround("bg.png");
    initUI();
    
    return true;
}

void HomeScene::initUI(){
    auto start = (Button*)(Helper::seekWidgetByName(m_pRootNode, "start"));
    start->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    
}

void HomeScene::onClick(Ref* ref, Widget::TouchEventType type){
    if(Widget::TouchEventType::ENDED != type) return;
    
    Widget* target = static_cast<Widget*>(ref);
    string name = target->getName();
    if (name.compare("start") == 0) {
        xGAME->enterChooseScene();
    }
}

bool HomeScene::keybackKeyDown(){
    return false;
}