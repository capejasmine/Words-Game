//
//  Appconfig.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/16.
//
//

#ifndef Appconfig_hpp
#define Appconfig_hpp

#include <stdio.h>

#define     Chinese_Record          "wordsgame_chinise_record"
#define     Listen_Record           "wordsgame_listen_record"
#define     Select_Record           "wordsgame_select_record"
#define     View_Record             "wordsgame_view_record"     

typedef enum{
    kListenType = 2222,
    kSelectType,
    kViewType,
    kMatchType,
    kChineseType
}GameType;

typedef enum{
    kAnimal = 4444,
    kFruit
}ItemType;



#endif /* Appconfig_hpp */
