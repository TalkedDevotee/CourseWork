#ifndef __LEVEL_3_H__
#define __LEVEL_3_H__

#include "cocos2d.h"

class Level_3 : public cocos2d::Scene
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
	void SwitchFourButton_ON();
	void SwitchFourButton_OFF();
	void TwoAndFour_ON();
	void TwoAndFour_OFF();
	void SwitchFiveButton_ON();
	void SwitchFiveButton_OFF();
	void FourAndFive_ON();
	void FourAndFive_OFF();
	void SwitchSixButton_ON();
	void SwitchSixButton_OFF();
	void SwitchSevenButton_ON();
	void SwitchSevenButton_OFF();
	void SixOrSeven_ON();
	void SixOrSeven_OFF();
	void RestartGame(float dt);
	void NextLevel(float dt);
	CREATE_FUNC(Level_3);
};

#endif