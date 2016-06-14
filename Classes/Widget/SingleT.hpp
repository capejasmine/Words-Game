//
//  SingleT.hpp
//  Words-Game
//
//  Created by huangwen on 16/6/14.
//
//

#ifndef SingleT_hpp
#define SingleT_hpp

#include <stdio.h>

#endif /* SingleT_hpp */


template <class T>
class SingleT{
public:
    virtual ~SingleT(){}
    static T* getInstance(){
        static T instance;
        return &instance;
    }
}