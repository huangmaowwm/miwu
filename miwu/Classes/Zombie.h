//
//  Zombie.h
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __Miwu__Zombie__
#define __Miwu__Zombie__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Zombie : public Enemy
{
    
private:
    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Zombie, create);
    
    
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void attack();
    virtual void sAttack();
};


#endif /* defined(__Miwu__Zombie__) */
