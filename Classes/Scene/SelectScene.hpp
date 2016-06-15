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
    static Scene* scene();
    
    CREATE_FUNC(SelectScene);
private:
    
};

#endif /* SelectScene_hpp */
