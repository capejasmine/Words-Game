//
//  ViewScene.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "ViewScene.hpp"

Scene* ViewScene::scene(){
    Scene* scene = Scene::create();
    ViewScene* layer = ViewScene::create();
    scene->addChild(layer);
    return scene;
}