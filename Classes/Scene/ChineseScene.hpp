//
//  ChineseScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef ChineseScene_hpp
#define ChineseScene_hpp

#include "BaseLayer.hpp"

class ChineseScene : public BaseLayer{
public:
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(ChineseScene);
    
    virtual bool keybackKeyDown();
private:
    
};

#endif /* ChineseScene_hpp */
