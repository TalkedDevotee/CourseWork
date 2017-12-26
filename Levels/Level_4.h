#ifndef __LEVEL_4_H__
#define __LEVEL_4_H__

#include "cocos2d.h"

class Level_4 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void SwitchOneButton_ON();
	void SwitchOneButton_OFF();
	void SwitchTwoButton_ON();
	void SwitchTwoButton_OFF();
	void OneOrTwo_ON();
	void OneOrTwo_OFF();
	void SwitchThreeButton_ON();
	void SwitchThreeButton_OFF();
	void SwitchFourButton_ON();
	void SwitchFourButton_OFF();
	void OneAndFour_ON();
	void OneAndFour_OFF();
	void SwitchFiveButton_ON();
	void SwitchFiveButton_OFF();
	void OneAndFive_ON();
	void OneAndFive_OFF();
	void SwitchSixButton_ON();
	void SwitchSixButton_OFF();
	void SwitchSevenButton_ON();
	void SwitchSevenButton_OFF();
	void OneOrSeven_ON();
	void OneOrSeven_OFF();
	void RestartGame(float dt);
	void LevelsCompleted(float dt);
	void GameOver(float dt);
	CREATE_FUNC(Level_4);
};

#endif