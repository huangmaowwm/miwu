//
//  AbilityLoader.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "AbilityLoader.h"

#include "LevelLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* AbilityLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("Ability", AbilityLoader::loader());
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Ability.ccbi");
    
    return node;
}