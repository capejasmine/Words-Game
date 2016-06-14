//
//  BaseLayer.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef BaseLayer_hpp
#define BaseLayer_hpp

#include <cocos2d.h>
#include "KeypadBoardDispatchCenter.hpp"
#include "CBLayer.hpp"
#include "ui/CocosGUI.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;
using namespace cocos2d::ui;
USING_NS_CC;

class BaseLayer : public CBLayer, KeypadDelegate{
public:
    
    virtual bool keybackKeyDown();
    
    virtual bool initWithFile(std::string pathNmae);
    
    void setBackGround(std::string path);
    
    void onButtonClick(Ref* event, TouchEventType type);
    
public:
    Node* m_pRootNode;
    
private:
    Sprite* m_pBgSprite;
};

#endif /* BaseLayer_hpp */
