//
//  GameController.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#include "GameController.hpp"

void GameController::enterLoading(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(Loading::scene());
    }else
    {
        xDirector->replaceScene(TransitionCrossFade::create(0.4, Loading::scene()));
    }
    m_curSceneType = kLoading;
}

void GameController::enterLoadingLayer(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(LoadingLayer::scene());
    }else
    {
        xDirector->replaceScene(TransitionCrossFade::create(0.4, LoadingLayer::scene()));
    }
    m_curSceneType = kLoadingLayer;
}

void GameController::enterHomeScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(HomeScene::scene());
    }else
    {
        xDirector->replaceScene(HomeScene::scene());
    }
    m_curSceneType = kHomeScene;
}

void GameController::enterChooseScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(ChooseScene::scene());
    }else
    {
        xDirector->replaceScene(ChooseScene::scene());
    }
    m_curSceneType = kChooseScene;
}

void GameController::enterViewScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(ViewScene::scene());
    }else
    {
        xDirector->replaceScene(ViewScene::scene());
    }
    m_curSceneType = kViewScene;
}

void GameController::enterListenScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(ListenScene::scene());
    }else
    {
        xDirector->replaceScene(ListenScene::scene());
    }
    m_curSceneType = kListenScene;
}

void GameController::enterChineseScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(ChineseScene::scene());
    }else
    {
        xDirector->replaceScene(ChineseScene::scene());
    }
    m_curSceneType = kChineseScene;
}

void GameController::enterSelectScene(){
    if (!xDirector->getRunningScene()) {
        xDirector->runWithScene(SelectScene::scene());
    }else
    {
        xDirector->replaceScene(SelectScene::scene());
    }
    m_curSceneType = kSelectScene;
}

kSceneType GameController::getCurentSceneType() {
    return m_curSceneType;
}
