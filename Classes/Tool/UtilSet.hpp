//
//  UtilSet.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef UtilSet_hpp
#define UtilSet_hpp

#include "cocos2d.h"
#include "GameController.hpp"
#include <stdio.h>

USING_NS_CC;

#define   xDirector       Director::getInstance()
#define   xGAME           GameController::getInstance()
#define   xUtil           UtilSet::getInstance()

#define   LOCK_LAYER      0x008801

class UtilSet : public Ref, public SingleT<UtilSet>{
public:
    void lockScreen();
    void unlockScreen();
};


#endif /* UtilSet_hpp */
