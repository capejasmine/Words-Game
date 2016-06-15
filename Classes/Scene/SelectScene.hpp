//
//  SelectScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef SelectScene_hpp
#define SelectScene_hpp

#include "BaseLayer.hpp"

class SelectScene : public BaseLayer{
public:
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(SelectScene);
    
    virtual bool keybackKeyDown();
private:
    
};

#endif /* SelectScene_hpp */
