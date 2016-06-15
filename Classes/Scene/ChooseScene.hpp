//
//  ChooseScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef ChooseScene_hpp
#define ChooseScene_hpp

#include "BaseLayer.hpp"

class ChooseScene : public BaseLayer{
public:
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(ChooseScene);
    
    virtual bool keybackKeyDown();
private:
    
};

#endif /* ChooseScene_hpp */
