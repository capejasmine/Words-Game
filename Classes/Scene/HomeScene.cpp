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
    
    return true;
}

bool HomeScene::keybackKeyDown(){
    return false;
}