//
//  ChineseScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "ChineseScene.hpp"

Scene* ChineseScene::scene(){
    Scene* scene = Scene::create();
    ChineseScene* layer = ChineseScene::create();
    scene->addChild(layer);
    return scene;
}