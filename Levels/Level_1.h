#ifndef __LEVEL_1_H__
#define __LEVEL_1_H__

#include "cocos2d.h"

class Level_1 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void SwitchOneButton_ON();
	void SwitchOneButton_OFF();
	void SwitchTwoButton_ON();
	void SwitchTwoButton_OFF();
	void SwitchThreeButton_ON();
	void SwitchThreeButton_OFF();
	void TwoAndTrhee_ON();
	void TwoAndTrhee_OFF();
	void SwitchFourButton_ON();
	void SwitchFourButton_OFF();
	void SwitchFiveButton_ON();
	void SwitchFiveButton_OFF();
	void SwitchSixButton_ON();
	void SwitchSixButton_OFF();
	void FiveOrSix_ON();
	void FiveOrSix_OFF();
	void RestartGame(float dt);
	void NextLevel(float dt);
	CREATE_FUNC(Level_1);
};

#endif