//
//  SelectScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "SelectScene.hpp"

Scene* SelectScene::scene(){
    Scene* scene = Scene::create();
    SelectScene* layer = SelectScene::create();
    scene->addChild(layer);
    return scene;
}