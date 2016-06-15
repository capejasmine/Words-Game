//
//  Loading.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "Loading.hpp"

Scene* Loading::scene(){
    Scene* scene = Scene::create();
    Loading* layer = Loading::create();
    scene->addChild(layer);
    return scene;
}