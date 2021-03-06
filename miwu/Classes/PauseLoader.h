//
//  PauseLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__PauseLoader__
#define __miwu__PauseLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Pause.h"

class PauseLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PauseLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Pause);
    
};


#endif /* defined(__miwu__PauseLoader__) */
