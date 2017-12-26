#ifndef __LEVEL_2_H__
#define __LEVEL_2_H__

#include "cocos2d.h"

class Level_2 : public cocos2d::Scene
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
	void TwoAndThree_ON();
	void TwoAndThree_OFF();
	void SwitchFourButton_ON();
	void SwitchFourButton_OFF();
	void OneOrFour_ON();
	void OneOrFour_OFF();
	void SwitchFiveButton_ON();
	void SwitchFiveButton_OFF();
	void FourOrFive_ON();
	void FourOrFive_OFF();
	void RestartGame(float dt);
	void NextLevel(float dt);
	CREATE_FUNC(Level_2);
};

#endif