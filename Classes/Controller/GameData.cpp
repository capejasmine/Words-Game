//
//  GameData.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/16.
//
//

#include "GameData.hpp"

string itemArr[] = {"Animal","Fruit"};

GameData::GameData(){
    m_KeyRoot = FileUtils::getInstance()->getValueMapFromFile("key.plist");
    m_ListenRoot = FileUtils::getInstance()->getValueMapFromFile("path.plist");
    m_SelectRoot = FileUtils::getInstance()->getValueMapFromFile("words.plist");
    m_ChineseRoot = FileUtils::getInstance()->getValueMapFromFile("message.plist");
    
    auto kinds = m_KeyRoot[getItemNameFromType(m_ItemType)].asValueVector();
    for (auto e : kinds) {
        m_vItemsType.pushBack(e.asString());
    }
}

void GameData::setGameType(GameType type){
    m_GameType = type;
}

void GameData::setItemType(ItemType type){
    m_ItemType = type;
}

string GameData::getItemNameFromType(ItemType type){
    switch (type) {
        case ItemType::kAnimal:
            return "Animal";
            break;
        case ItemType::kFruit:
            return "Fruit";
        default:
            break;
    }
}

string GameData::getCorrectWords(){
    auto kinds = m_KeyRoot[getItemNameFromType(m_ItemType)].asValueVector();
    return kinds.at(m_iRecord).asString();
}
//      gametype    itemtype   data
string GameData::getDataFromKey(){
    
    if (m_GameType == kListenType) {
        return getListenData();
    }
    else if (m_GameType == kViewType){
        return getViewData();
    }
    else if (m_GameType == kChineseType){
        return getChineseData();
    }
    else
    {
        return getSelectData();
    }
    
}

string GameData::getSelectData(){
    string words = m_SelectRoot[this->getCorrectWords()].asString();
    return words;
}
string GameData::getViewData(){
    string viewPath;
    viewPath = StringUtils::format("game/view/%s.png",this->getCorrectWords().c_str());
    return viewPath;
}

string GameData::getListenData(){
    string path;
    path = m_ListenRoot[getCorrectWords()].asString();
    return path;
}

string GameData::getChineseData(){
    string messages = m_ChineseRoot[getCorrectWords()].asString();
    return messages;
}

void GameData::saveRecord(){
    for (auto e : m_vItemsType) {
        string key = StringUtils::format("gamewords_%s",e.c_str());
        
    }
}





