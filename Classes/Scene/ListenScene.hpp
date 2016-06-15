//
//  ListenScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef ListenScene_hpp
#define ListenScene_hpp

#include "BaseLayer.hpp"

class ListenScene : public BaseLayer{
public:
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(ListenScene);
    
    virtual bool keybackKeyDown();
private:
    
};

#endif /* ListenScene_hpp */
