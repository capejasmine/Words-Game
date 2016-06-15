//
//  ViewScene.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/15.
//
//

#ifndef ViewScene_hpp
#define ViewScene_hpp

#include "BaseLayer.hpp"

class ViewScene : public BaseLayer{
public:
    static Scene* scene();
    
    CREATE_FUNC(ViewScene);
private:

};

#endif /* ViewScene_hpp */
