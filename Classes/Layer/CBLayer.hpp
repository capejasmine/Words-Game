//
//  CBLayer.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef CBLayer_hpp
#define CBLayer_hpp

#include <cocos2d.h>

USING_NS_CC;

typedef enum{
    kBackground = 0,
    kContent = 50,
    kUi = 100,
    kPop = 200
}LayerZoder;

class CBLayer : public Layer{
public:
    virtual bool init();
    
    void addToUiLayer(Node*, int zoder = 0, int tag = 0);
    
    void addToContentLayer(Node*, int zoder = 0, int tag = 0);
    
    void addToBgLayer(Node*, int zoder = 0, int tag = 0);
    
    void addToPopLayer(Node*, int zoder = 0, int tag = 0);
private:
    Layer* m_pUiLayer;
    Layer* m_pContentLayer;
    Layer* m_pBgLayer;
    Layer* m_pPopLayer;
};

#endif /* CBLayer_hpp */
