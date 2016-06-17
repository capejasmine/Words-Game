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
    m_RecordRoot = FileUtils::getInstance()->getValueMapFromFile("record.plist");
    
}

void GameData::setGameType(GameType type){
    m_GameType = type;
}

void GameData::setItemType(ItemType type){
    m_ItemType = type;
    
    auto kinds = m_KeyRoot[getItemNameFromType(m_ItemType)].asValueVector();
    for (auto e : kinds) {
        m_vItemsType.push_back(e.asString());
    }
    
    if (!isRecordExit()) {
        log("不存在历史记录");
        m_iRecord = 0;
    }
    else
    {
        auto record_root = FileUtils::getInstance()->getValueMapFromFile("record.plist");
        for (auto e : m_vItemsType) {
            Value data = m_RecordRoot[e.c_str()];
            ValueMap ret;
            ret[e.c_str()] = data;
            
            // 初始化 历史记录
            if(getItemNameFromType(m_ItemType) == e.c_str()){
                m_iRecord = data.asInt();
            }
        }
    }

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
string GameData::getData(){
    
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
    this->removeRocord();
    
    ValueMap record;
    for (auto e : m_vItemsType) {
        if(getItemNameFromType(m_ItemType) == e.c_str()){
            record[e] = m_iRecord;
        }else
        {
            record[e] = m_RecordRoot[e.c_str()];
        }
    }
    
    auto fullPath = xFile->getWritablePath() + "record.plist";
    log("数据存储位置: %s",fullPath.c_str());
    if(xFile->writeToFile(record, fullPath)){
        log("保存成功");
    }
}

bool GameData::isRecordExit(){
    auto writePath = xFile->getWritablePath() + "record.plist";
    
    log("数据位置: %s",writePath.c_str());
    return xFile->isFileExist(writePath);
}

void GameData::removeRocord(){
    if (isRecordExit()) {
        auto fullPath = xFile->getWritablePath() + "record.plist";
        std::remove(fullPath.c_str());
        
    }
}





