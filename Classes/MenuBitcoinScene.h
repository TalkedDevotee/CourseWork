#ifndef __MENUBITCOIN_SCENE_H__
#define __MENUBITCOIN_SCENE_H__

#include "cocos2d.h"

class MenuBitcoinScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuStartCallBack(cocos2d::Ref* pSender);
	CREATE_FUNC(MenuBitcoinScene);
};

#endif