//
//  Level.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Level.h"

#include "GameObject.h"
#include "Rabit.h"
#include "Zombie.h"
#include "Bear.h"
#include "BearLoader.h"
#include "RabitLoader.h"

#define kCJScrollFilterFactor 0.1
#define kCJRabitTargetOffset 156

USING_NS_CC;
USING_NS_CC_EXT;

void Level::onEnter()
{
    CCLayer::onEnter();
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
}

void Level::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();

    CCLayer::onExit();
}

bool Level::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Level::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rabit", Rabit*, this->rabit);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "zombie", Zombie*, this->zombie);
    
    return false;
}

void Level::update(float delta)
{
    // Iterate through all objects in the level layer
    CCObject* child = NULL;
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        // Check if the child is a game object
        if (gameObject != NULL)
        {
            
            // Update all game objects
            gameObject->update();
            
            // Check for collisions with dragon
            if (gameObject == zombie)
            {
                Bear* bear = dynamic_cast<Bear*>(this->getChildByTag(101));
                if (bear!=NULL && ccpDistance(gameObject->getPosition(), bear->getPosition()) < gameObject->radius() + bear->radius())
                {
                    // Notify the game objects that they have collided
                    gameObject->handleCollisionWith(bear);
                    rabit->handleCollisionWith(gameObject);
                }
                
                if (ccpDistance(gameObject->getPosition(), rabit->getPosition()) < gameObject->radius() + rabit->radius())
                {
                    // Notify the game objects that they have collided
                    gameObject->handleCollisionWith(rabit);
                    rabit->handleCollisionWith(gameObject);
                }
            }
        }
    }
    
    // Check for objects to remove
    CCArray* gameObjectsToRemove = CCArray::create();
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        if (gameObject != NULL)
        {
            
            if (gameObject->getIsScheduledForRemove())
            {
                gameObjectsToRemove->addObject(gameObject); 
            }
        }
    }
    
    GameObject* gameObject = NULL;
    for(int i = 0; i < gameObjectsToRemove->count(); i++)
    {
        gameObject = dynamic_cast<GameObject*>(gameObjectsToRemove->objectAtIndex(i));
        this->removeChild(gameObject, true);
    }
}

/*
void Level::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //cocos2d::CCNode* rabit = RabitLoader::load();
    //rabit->setPosition(ccp(touchLocation.x, touchLocation.y));
    //this->addChild(rabit);
    cocos2d::CCNode* bear = BearLoader::load();
    bear->setPosition(ccp(touchLocation.x, touchLocation.y));
    bear->setTag(101);
    this->addChild(bear);

    //dragon->setXTarget(touchLocation.x);
}

void Level::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //dragon->setXTarget(touchLocation.x);
}
*/