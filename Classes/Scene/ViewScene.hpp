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
    virtual bool init();
    
    static Scene* scene();
    
    CREATE_FUNC(ViewScene);
    
    virtual bool keybackKeyDown();
private:

};

#endif /* ViewScene_hpp */
