//
//  LoadingLayer.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "LoadingLayer.hpp"

Scene* LoadingLayer::scene(){
    Scene* scene = Scene::create();
    LoadingLayer* layer = LoadingLayer::create();
    scene->addChild(layer);
    return scene;
}