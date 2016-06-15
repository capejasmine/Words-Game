//
//  ListenScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "ListenScene.hpp"

Scene* ListenScene::scene(){
    Scene* scene = Scene::create();
    ListenScene* layer = ListenScene::create();
    scene->addChild(layer);
    return scene;
}