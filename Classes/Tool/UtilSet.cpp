//
//  UtilSet.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "UtilSet.hpp"

void UtilSet::lockScreen(){
    auto scene = xDirector->getRunningScene();
    LayerColor* layer = LayerColor::create(cocos2d::Color4B(255, 0, 0, 0));
    scene->addChild(scene);
    layer->setContentSize(xDirector->getVisibleSize());
    layer->setAnchorPoint(Point::ZERO);
    layer->setPosition(Point::ZERO);
    layer->setTag(INT_MAX);
    layer->setZOrder(LOCK_LAYER);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch *touch, Event *event){
        return true;
    };
    listener->setSwallowTouches(true);
    xDirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}

void UtilSet::unlockScreen(){
    auto scene = xDirector->getRunningScene();
    auto layer = scene->getChildByTag(INT_MAX);
    if(layer){
        layer->removeFromParentAndCleanup(true);
    }
    
}