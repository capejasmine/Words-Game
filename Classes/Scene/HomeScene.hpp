//
//  HomeScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef HomeScene_hpp
#define HomeScene_hpp

#include "BaseLayer.hpp"
#include "UtilSet.hpp"
#include "KeyBoardLayer.hpp"


class HomeScene : public BaseLayer{
public:
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(HomeScene);
    
    virtual bool keybackKeyDown();
    
    void initUI();
    
    void onClick(Ref* ref, Widget::TouchEventType type);
    
    void keyBoardOnClick(string s);
private:
    
    Label* m_lable;
    
    KeyBoardLayer* m_layer;
};

#endif /* HomeScene_hpp */
