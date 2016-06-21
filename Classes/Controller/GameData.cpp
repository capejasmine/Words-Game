//
//  GameData.cpp
//  Words-Game
//
//  Created by huangwen on 16/6/16.
//
//

// 1  关卡选择 设置 游戏类型                  setGameType(arg)
// 2  种类选择 设置 游戏item                  setItemType(arg)
// 3  游戏场景调用 getData   回答正确调用       addRecord()
// 4  游戏退出 保存数据                         saveRecord()

// 新增 物品 需添加 plist文件内容 以及 getItemNameFromType 借口 内容;  后期更改

#include "GameData.hpp"

string itemArr[] = {"Animal","Fruit"};

GameData* GameData::m_pInstance = nullptr;

GameData* GameData::getInstance(){
    if (!m_pInstance) {
        m_pInstance = new GameData();
    }
    return m_pInstance;
}


GameData::GameData(){
    m_KeyRoot = FileUtils::getInstance()->getValueMapFromFile("key.plist");
    m_ListenRoot = FileUtils::getInstance()->getValueMapFromFile("path.plist");
    m_SelectRoot = FileUtils::getInstance()->getValueMapFromFile("words.plist");
    m_ChineseRoot = FileUtils::getInstance()->getValueMapFromFile("message.plist");
    m_RecordRoot = FileUtils::getInstance()->getValueMapFromFile(xFile->getWritablePath() + "record.plist");
    
}

void GameData::setGameType(GameType type){
    m_GameType = type;
}

void GameData::setItemType(ItemType type){
    m_ItemType = type;
    
    log("%s",getItemNameFromType(m_ItemType).c_str());
    //auto kinds = m_KeyRoot[getItemNameFromType(m_ItemType)].asValueVector();
    for (auto e : m_KeyRoot) {
        m_vItemsType.push_back(e.first);
    }
    
    if (!isRecordExit()) {
        log("--------------不存在历史记录-----------------");
        m_iRecord = 0;
    }
    else
    {
        for (auto e : m_vItemsType) {
            auto data = m_RecordRoot[e].asInt();
            ValueMap ret;
            ret[e.c_str()] = data;
            
            // 初始化 历史记录
            if(getItemNameFromType(m_ItemType) == e.c_str()){
                m_iRecord = data;
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
    //log("--------------正确的 %s----------------", kinds.at(m_iRecord).asString().c_str());
    return kinds.at(m_iRecord).asString();
}
//      gametype    itemtype   data
string GameData::getData(){
    string data;
    if (m_GameType == kListenType) {
        data =  getListenData();
    }
    else if (m_GameType == kViewType){
        data =  getViewData();
    }
    else if (m_GameType == kChineseType){
        data =  getChineseData();
    }
    else
    {
        data =  getSelectData();
    }
    return data;
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
    //this->removeRocord();
    
    ValueMap record;
    for (auto e : m_KeyRoot) {
        if(getItemNameFromType(m_ItemType) == e.first){
            record[e.first] = m_iRecord;
        }
        else
        {
            record[e.first] = m_RecordRoot[e.first].asInt() ? m_RecordRoot[e.first].asInt() : 0;
            
        }
    }
    
    auto fullPath = xFile->getWritablePath() + "record.plist";
    log("---------数据存储位置: %s-----------",fullPath.c_str());
    if(xFile->writeToFile(record, fullPath)){
        log("保存成功");
    }
}

bool GameData::isRecordExit(){
    auto writePath = xFile->getWritablePath() + "record.plist";
    
    log("----------数据位置: %s------------",writePath.c_str());
    return xFile->isFileExist(writePath);
}

void GameData::removeRocord(){
    if (isRecordExit()) {
        auto fullPath = xFile->getWritablePath() + "record.plist";
        std::remove(fullPath.c_str());
        
    }
}

bool GameData::isTrue(string words) {
    if (this->getCorrectWords().compare(words) == 0) {
        xData->addRecord();
        return true;
    }
    return false;
}




