//
//  S6.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S6__
#define __miwu__S6__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S6_BASE_HP 180
#define kCJ_S6_BASE_ATK 20
#define kCJ_S6_StartSpeed 60
#define kCJ_S6_ACTION_RANGE 1
#define kCJ_S6_ATK_DELAY 1
#define kCJ_S6_NORMAL_SKILL_RATE 100
#define kCJ_S6_HALO_SKILL_RATE 100

class S6 : public Soldier
{

private:    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S6, create);
    
    virtual float radius();
    virtual float getLv();
    virtual void handleCollisionWith(GameObject* gameObject);
    void healHandler(GameObject* gameObject);
};

#endif /* defined(__miwu__S6__) */
