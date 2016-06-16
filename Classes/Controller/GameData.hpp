//
//  GameData.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/16.
//
//

#ifndef GameData_hpp
#define GameData_hpp

#include "SingleT.hpp"
#include "cocos2d.h"
#include "stdio.h"
#include "Appconfig.hpp"

#define     xData      GameData::getInstance()

USING_NS_CC;
using namespace std;

class GameData : public SingleT<GameData>{
public:
    GameData();
    
    void setGameType(GameType type);
    
    void setItemType(ItemType type);
    
    string getItemNameFromType(ItemType type);
    
    string getDataFromKey();
    
    string getSelectData();
    
    string getViewData();
    
    string getListenData();
    
    string getChineseData();
    
    string getCorrectWords();
    
    void saveRecord();
    
    void addRecord(){
        m_iRecord++;
    }
    
private:
    ValueMap m_KeyRoot;
    
    ValueMap m_ListenRoot;
    
    ValueMap m_SelectRoot;
    
    ValueMap m_ChineseRoot;
    //  游戏方式
    GameType m_GameType;
    
    ItemType m_ItemType;
    
    int m_iRecord = 0;
};

#endif /* GameData_hpp */
