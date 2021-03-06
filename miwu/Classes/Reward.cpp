//
//  Reward.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Reward.h"

#include "cocos2d.h"
#include "RewardLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Reward::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Reward::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    }
    
    return true;
}
