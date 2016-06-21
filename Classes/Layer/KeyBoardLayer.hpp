//
//  KeyBoardLayer.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/21.
//
//

#ifndef KeyBoardLayer_hpp
#define KeyBoardLayer_hpp

#include <stdio.h>
#include "BaseLayer.hpp"

class KeyBoardLayer : public BaseLayer{
public:
    static KeyBoardLayer* create();
    
    virtual bool init();
    
private:
    
    
};

#endif /* KeyBoardLayer_hpp */
