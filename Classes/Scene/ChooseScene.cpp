//
//  ChooseScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "ChooseScene.hpp"

Scene* ChooseScene::scene(){
    Scene* scene = Scene::create();
    ChooseScene* layer = ChooseScene::create();
    scene->addChild(layer);
    return scene;
}