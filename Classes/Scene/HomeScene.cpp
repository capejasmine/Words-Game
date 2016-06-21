//
//  HomeScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "HomeScene.hpp"
#include "GameData.hpp"

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
    //initUI();
    
    _lable = Label::create();
    _lable->setPosition(Director::getInstance()->getWinSize()/2);
    _lable->setSystemFontSize(40);
    _lable->setSystemFontName("Ready");
    _lable->setTextColor(cocos2d::Color4B(255, 255, 255, 255));
    this->addChild(_lable);
    
    Button* btn1 = Button::create("popup_ok_default.png");
    btn1->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn1->setPosition(Vec2(200, 200));
    btn1->setName("start");
    addChild(btn1);
    
    Button* btn2 = Button::create("popup_cancel_default.png");
    btn2->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn2->setPosition(Vec2(400, 200));
    btn2->setName("save");
    addChild(btn2);
    
    Button* btn3 = Button::create("popup_cancel_default.png");
    btn3->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn3->setPosition(Vec2(600, 200));
    btn3->setName("save1");
    addChild(btn3);
    
    xData->setGameType(GameType::kChineseType);
    xData->setItemType(ItemType::kAnimal);

    
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
        //xGAME->enterChooseScene();
        string data = xData->getData();
        _lable->setString(data);
    }
    if (name.compare("save") == 0) {
        
        xData->addRecord();
        
        string data = xData->getData();
        _lable->setString(data);
    }
    
    if (name.compare("save1") == 0) {
        xData->saveRecord();
    }

}

bool HomeScene::keybackKeyDown(){
    return false;
}