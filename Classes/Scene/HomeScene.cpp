//
//  HomeScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#include "HomeScene.hpp"
#include "GameData.hpp"
#include "stdio.h"
#include "stdlib.h"
#include "curl.h"


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
    

    
    Button* btn1 = Button::create("popup_ok_default.png");
    btn1->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn1->setPosition(Vec2(200, 500));
    btn1->setName("start");
    addChild(btn1);
    
    Button* btn2 = Button::create("popup_cancel_default.png");
    btn2->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn2->setPosition(Vec2(400, 500));
    btn2->setName("save");
    addChild(btn2);
    
    Button* btn3 = Button::create("popup_cancel_default.png");
    btn3->addTouchEventListener(CC_CALLBACK_2(HomeScene::onClick, this));
    btn3->setPosition(Vec2(600, 500));
    btn3->setName("save1");
    addChild(btn3);
    
    xData->setGameType(GameType::kChineseType);
    xData->setItemType(ItemType::kAnimal);
    
    m_lable = Label::create();
    m_lable->setPosition(xDirector->getWinSize()/2);
    m_lable->setSystemFontSize(50);
    m_lable->setSystemFontName("Marker Felt.ttf");
    m_lable->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    this->addChild(m_lable);

    m_layer = KeyBoardLayer::create();
    this->addChild(m_layer,1000);
    
    m_layer->setTouchEvent(CC_CALLBACK_1(HomeScene::keyBoardOnClick, this));
    
    return true;
}

void HomeScene::keyBoardOnClick(string s){
    log("touch =  %s",s.c_str());
    string content = m_lable->getString();
    if(s.compare("backspace") == 0){
        if(content.length() != 0){
            content.erase(content.end() - 1);
            m_lable->setString(content);
        }
    }
    else
    {
        if(content.length() > 12){
            log("超过对最大限度");
            return;
        }
        else
        {
            string new_content = content + s;
            m_lable->setString(new_content);
        }
    }
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
        if(m_lable->getString().compare(xData->getCorrectWords()) == 0){
            log("pass");
            xData->addRecord();
            m_lable->setString("");
        }
        
    }
    if (name.compare("save") == 0) {
        m_layer->hideToBottom();
//        xData->addRecord();
//        
//        string data = xData->getData();
//        _lable->setString(data);
    }
    
    if (name.compare("save1") == 0) {
        m_layer->showFromBottom();
        //xData->saveRecord();
    }

}

bool HomeScene::keybackKeyDown(){
    return false;
}