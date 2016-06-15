//
//  GameController.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include "HomeScene.hpp"
#include "ChooseScene.hpp"
#include "ViewScene.hpp"
#include "ListenScene.hpp"
#include "ChineseScene.hpp"
#include "SelectScene.hpp"
#include "Loading.hpp"
#include "LoadingLayer.hpp"
#include "UtilSet.hpp"

typedef enum{
    kLoading = 1111,
    kLoadingLayer,
    kHomeScene,
    kChooseScene,
    kViewScene,
    kListenScene,
    kChineseScene,
    kSelectScene
} kSceneType;

class GameController : public SingleT<GameController>{
public:
    void enterLoading();
    void enterLoadingLayer();
    void enterHomeScene();
    void enterChooseScene();
    void enterViewScene();
    void enterListenScene();
    void enterChineseScene();
    void enterSelectScene();
public:
    kSceneType getCurentSceneType();
private:
    kSceneType m_curSceneType;
};

#endif /* GameController_hpp */
