//
//  RabitLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__RabitLoader__
#define __Miwu__RabitLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Rabit.h"

class RabitLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RabitLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Rabit);
    
};


#endif /* defined(__Miwu__RabitLoader__) */