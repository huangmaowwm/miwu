//
//  Zombie.cpp
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "Zombie.h"

#include "S1.h"
#include "GameScene.h"


#define kCJStartSpeed -1.0
#define kCJHP 100
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool Zombie::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

void Zombie::update(float delta)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = oldPosition.x + xSpeed*delta;
    this->setPosition(ccp(xNew, oldPosition.y));
}

void Zombie::handleCollisionWith(GameObject* gameObject)
{
    if (this->hp<=0) {
        this->isScheduledForRemove = true;
    }
    S1* rabit = dynamic_cast<S1*>(gameObject);
    
    
    if (rabit != NULL) {
        xSpeed = 0;
        rabit->setHp(rabit->getHp()-this->atk);
        CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
        animationManager->runAnimationsForSequenceNamed("attack");
    }
}

void Zombie::attack()
{}

void Zombie::sAttack()
{}

float Zombie::radius()
{
    return 50.0f;
}