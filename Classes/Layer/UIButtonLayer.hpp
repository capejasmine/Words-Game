//
//  UIButtonLayer.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef UIButtonLayer_hpp
#define UIButtonLayer_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CocoStudio.h"
#include "CBLayer.hpp"

using namespace cocostudio;
using namespace cocos2d::ui;
USING_NS_CC;

class UIButtonLayer: public CBLayer{
public:
    virtual bool init(std::string csbPath);
    
    static UIButtonLayer* craete(std::string csbPath);
    
    void onButtonClick(Ref* ref, TouchEventType type);
    
private:
    static UIButtonLayer* layer;
};

#endif /* UIButtonLayer_hpp */
