#include "MenuBitcoinScene.h"
#include "Level_3.h"
#include "Level_4.h"
#include "ui\UIButton.h"
#include "BooleanAlgebra\Functions.h"

USING_NS_CC;

functions lv3;
extern struct IntCoin c;

extern bool stop;

bool checked2_3 = false; // "И" от 2-ого и 3-его, 4-ого выключателей
bool checked3_3 = false; // "И" от 3-его, 4-ого и 5-ого выключателей
bool checked4_3 = false; // "ИЛИ" от 6-ого и 7-ого выключателей

bool falled1_3 = false;

Scene* Level_3::createScene()
{
	return Level_3::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Level_3.cpp\n");
}

bool Level_3::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Sprites/Level_3/Background_level_3.png");
	if (sprite == nullptr)
	{
		problemLoading("'Background_level_3.png'");
	}
	else
	{
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(sprite, 0);
	}

	auto block = Sprite::create("Sprites/block.png");
	if (block == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block->setPosition(Vec2(420, 263));
		block->setTag(1);
		this->addChild(block, 1);
	}

	auto block2 = Sprite::create("Sprites/block.png");
	if (block2 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block2->setPosition(Vec2(375, 209));
		block2->setTag(2);
		this->addChild(block2, 1);
	}

	auto block3 = Sprite::create("Sprites/block.png");
	if (block3 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block3->setPosition(Vec2(375, 160));
		block3->setTag(3);
		this->addChild(block3, 1);
	}

	auto block4 = Sprite::create("Sprites/block.png");
	if (block4 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block4->setPosition(Vec2(420, 109));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto block5 = Sprite::create("Sprites/block.png");
	if (block5 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block5->setPosition(Vec2(375, 52));
		block5->setTag(5);
		this->addChild(block5, 1);
	}

	auto coin = Sprite::create("Sprites/Coin.png");
	if (coin == nullptr)
	{
		problemLoading("'Coin.png'");
	}
	else
	{
		coin->setPosition(Vec2(425, 289));
		coin->setTag(71);
		this->addChild(coin, 1);
	}

	auto Coins = Label::createWithTTF("LEVEL 3", "fonts/bitcoin.ttf", 15);
	Coins->setPosition(Vec2(35, 305));
	Coins->setColor(Color3B::BLACK);
	this->addChild(Coins, 1);

	auto NumberCoins = Label::createWithTTF("Coins:", "fonts/bitcoin.ttf", 15);
	NumberCoins->setPosition(Vec2(312, 305));
	NumberCoins->setColor(Color3B::BLACK);
	this->addChild(NumberCoins, 1);

	if (c.IntCoins > 1)
	{
		auto LabelCoins = Sprite::create("Buttons_labels/LabelCoin.png");
		LabelCoins->setPosition(Vec2(345, 305));
		this->addChild(LabelCoins, 1);
	}

	if (c.IntCoins > 2)
	{
		auto LabelCoins1 = Sprite::create("Buttons_labels/LabelCoin.png");
		LabelCoins1->setPosition(Vec2(362, 305));
		this->addChild(LabelCoins1, 1);
	}

	if (c.IntCoins > 3)
	{
		auto LabelCoins2 = Sprite::create("Buttons_labels/LabelCoin.png");
		LabelCoins2->setPosition(Vec2(379, 305));
		this->addChild(LabelCoins2, 1);
	}

	auto Switch_ONE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 282));
		Switch_ONE->setTag(10);
		this->addChild(Switch_ONE, 1);
	}

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw1 = true;
			removeChildByTag(1);
			removeChildByTag(10);
			SwitchOneButton_ON();
			break;
		}
	});

	auto Switch_TWO = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 225));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw2 = lv3.not1 = true;
			removeChildByTag(20);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			SwitchTwoButton_ON();
			break;
		}
	});

	auto Switch_THREE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 183));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw3 = true;
			if (lv3.AND(lv3.sw3, lv3.sw4) == true)
				lv3.and1 = true;
			removeChildByTag(30);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchThreeButton_ON();
			break;
		}
	});

	auto Switch_FOUR = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 150));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw4 = true;
			if (lv3.AND(lv3.sw3, lv3.sw4) == true)
				lv3.and1 = true;
			removeChildByTag(40);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchFourButton_ON();
			break;
		}
	});

	auto Switch_FIVE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 109));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw5 = lv3.not2 = true;
			removeChildByTag(4);
			removeChildByTag(50);
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchFiveButton_ON();
			break;
		}
	});

	auto Switch_SIX = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 69));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw6 = true;
			removeChildByTag(60);
			if (lv3.OR(lv3.sw6, lv3.sw7) == true && checked4_3 == false)
			{
				lv3.or1 = true;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == false)
				{
					lv3.not3 = false;
					SixOrSeven_ON();
				}
				checked4_3 = true;
			}
			SwitchSixButton_ON();
			break;
		}
	});

	auto Switch_SEVEN = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SEVEN == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_SEVEN->setPosition(Vec2(60, 36));
		Switch_SEVEN->setTag(70);
		this->addChild(Switch_SEVEN, 1);
	}

	Switch_SEVEN->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw7 = true;
			if (lv3.OR(lv3.sw6, lv3.sw7) == true && checked4_3 == false)
			{
				lv3.or1 = true;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == false)
				{
					lv3.not3 = false;
					SixOrSeven_ON();
				}
				checked4_3 = true;
			}
			SwitchSevenButton_ON();
			break;
		}
	});

	return true;
}

void Level_3::SwitchOneButton_ON()
{
	auto Switch_ONE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 282));
		Switch_ONE->setTag(10);
		this->addChild(Switch_ONE, 1);
	}

	auto block = Sprite::create("Sprites/block.png");
	if (block == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block->setPosition(Vec2(420, 263));
		block->setTag(1);
		this->addChild(block, 1);
	}

	if (lv3.moved == false && checked2_3 == false && checked3_3 == false && lv3.sw5 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 289));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -154));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 2.0f);
	}

	if (lv3.moved == false && checked2_3 == false && checked3_3 == false && lv3.sw5 == true && checked4_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 289));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(2.5, Vec2(0, -255));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 3.0f);
	}

	if (lv3.moved == false && checked2_3 == true && falled1_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 289));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -54));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv3.moved = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	if (lv3.NOT(lv3.sw1) == false)
		block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw1 = false;
			removeChildByTag(1);
			removeChildByTag(10);
			SwitchOneButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchOneButton_OFF()
{
	auto Switch_ONE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 282));
		Switch_ONE->setTag(10);
		this->addChild(Switch_ONE, 1);
	}

	auto block = Sprite::create("Sprites/block.png");
	if (block == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block->setPosition(Vec2(375, 263));
		block->setTag(1);
		this->addChild(block, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	if (lv3.NOT(lv3.sw1) == true)
		block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw1 = true;
			removeChildByTag(1);
			removeChildByTag(10);
			SwitchOneButton_ON();
			break;
		}
	});
}

void Level_3::SwitchTwoButton_ON()
{
	auto Switch_TWO = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 225));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw2 = lv3.not1 = false;
			removeChildByTag(20);
			if (lv3.AND(lv3.not1, lv3.and1) == false && checked2_3 == true)
			{
				removeChildByTag(2);
				TwoAndFour_OFF();
				checked2_3 = false;
			}
			SwitchTwoButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchTwoButton_OFF()
{

	auto Switch_TWO = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 225));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw2 = lv3.not1 = true;
			removeChildByTag(20);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			SwitchTwoButton_ON();
			break;
		}
	});
}

void Level_3::SwitchThreeButton_ON()
{
	auto Switch_THREE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 183));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw3 = false;
			if (lv3.AND(lv3.sw3, lv3.sw4) == false)
				lv3.and1 = false;
			removeChildByTag(30);
			if (lv3.AND(lv3.not1, lv3.and1) == false && checked2_3 == true)
			{
				removeChildByTag(2);
				TwoAndFour_OFF();
				checked2_3 = false;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == false && checked3_3 == true)
			{
				removeChildByTag(3);
				FourAndFive_OFF();
				checked3_3 = false;
			}
			SwitchThreeButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchThreeButton_OFF()
{
	auto Switch_THREE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 183));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw3 = true;
			if (lv3.AND(lv3.sw3, lv3.sw4) == true)
				lv3.and1 = true;
			removeChildByTag(30);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchThreeButton_ON();
			break;
		}
	});
}

void Level_3::SwitchFourButton_ON()
{
	auto Switch_FOUR = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 150));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw4 = false;
			if (lv3.AND(lv3.sw3, lv3.sw4) == false)
				lv3.and1 = false;
			removeChildByTag(40);
			if (lv3.AND(lv3.not1, lv3.and1) == false && checked2_3 == true)
			{
				removeChildByTag(2);
				TwoAndFour_OFF();
				checked2_3 = false;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == false && checked3_3 == true)
			{
				removeChildByTag(3);
				FourAndFive_OFF();
				checked3_3 = false;
			}
			SwitchFourButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchFourButton_OFF()
{
	auto Switch_FOUR = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 150));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw4 = true;
			if (lv3.AND(lv3.sw3, lv3.sw4) == true)
				lv3.and1 = true;
			removeChildByTag(40);
			if (lv3.AND(lv3.not1, lv3.and1) == true && checked2_3 == false)
			{
				removeChildByTag(2);
				TwoAndFour_ON();
				checked2_3 = true;
			}
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchFourButton_ON();
			break;
		}
	});
}

void Level_3::TwoAndFour_ON()
{
	auto block2 = Sprite::create("Sprites/block.png");
	if (block2 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block2->setPosition(Vec2(375, 209));
		block2->setTag(2);
		this->addChild(block2, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block2->runAction(MoveBy);
}

void Level_3::TwoAndFour_OFF()
{
	auto block2 = Sprite::create("Sprites/block.png");
	if (block2 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block2->setPosition(Vec2(420, 209));
		block2->setTag(2);
		this->addChild(block2, 1);
	}

	if (lv3.moved == true && lv3.moved1 == false && checked3_3 == false && lv3.sw5 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 235));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -100));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 1.5f);
	}

	if (lv3.sw2 == true && lv3.moved == true && lv3.moved1 == false && checked3_3 == true && checked4_3 == false && lv3.sw5 == true)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 235));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(2, Vec2(0, -201));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 2.5f);
	}

	if (lv3.moved == true && lv3.moved1 == false && checked3_3 == true && checked4_3 == true && lv3.sw5 == true)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 235));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -157));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 2.0f);
	}

	if (lv3.moved == true && lv3.moved1 == false && checked3_3 == true && falled1_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 235));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -49));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv3.moved1 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block2->runAction(MoveBy);
}

void Level_3::SwitchFiveButton_ON()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 109));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	auto block4 = Sprite::create("Sprites/block.png");
	if (block4 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block4->setPosition(Vec2(420, 109));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block4->runAction(MoveBy);

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw5 = lv3.not2 = false;
			removeChildByTag(4);
			removeChildByTag(50);
			if (lv3.AND(lv3.and1, lv3.not2) == false && checked3_3 == true)
			{
				removeChildByTag(3);
				FourAndFive_OFF();
				checked3_3 = false;
			}
			SwitchFiveButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchFiveButton_OFF()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 109));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	auto block4 = Sprite::create("Sprites/block.png");
	if (block4 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block4->setPosition(Vec2(375, 109));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block4->runAction(MoveBy);

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw5 = lv3.not2 = true;
			removeChildByTag(4);
			removeChildByTag(50);
			if (lv3.AND(lv3.and1, lv3.not2) == true && checked3_3 == false)
			{
				removeChildByTag(3);
				FourAndFive_ON();
				checked3_3 = true;
			}
			SwitchFiveButton_ON();
			break;
		}
	});
}

void Level_3::FourAndFive_ON()
{
	auto block3 = Sprite::create("Sprites/block.png");
	if (block3 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block3->setPosition(Vec2(375, 160));
		block3->setTag(3);
		this->addChild(block3, 1);
	}

	if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == true && lv3.moved3 == false && checked3_3 == false && checked4_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 135));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -101));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 1.5f);
	}

	if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == true && lv3.moved3 == false && checked4_3 == true && falled1_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 135));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -57));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv3.moved3 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block3->runAction(MoveBy);
}

void Level_3::FourAndFive_OFF()
{
	auto block3 = Sprite::create("Sprites/block.png");
	if (block3 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block3->setPosition(Vec2(420, 160));
		block3->setTag(3);
		this->addChild(block3, 1);
	}

	if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == false && lv3.sw5 == true && falled1_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 186));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -151));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 2.0f);
	}

	if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == false && lv3.sw5 == true && falled1_3 == true)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 186));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -108));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_3 = true;

		this->schedule(schedule_selector(Level_3::RestartGame), 1.5f);
	}

	if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == false && lv3.sw5 == false && falled1_3 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 186));
			coin->setTag(71);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -51));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv3.moved2 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block3->runAction(MoveBy);
}

void Level_3::SwitchSixButton_ON()
{
	auto Switch_SIX = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 69));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw6 = false;
			removeChildByTag(60);
			if (lv3.OR(lv3.sw6, lv3.sw7) == false && checked4_3 == true)
			{
				lv3.or1 = false;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == true)
				{
					lv3.not3 = true;
					SixOrSeven_OFF();
				}
				checked4_3 = false;
			}
			SwitchSixButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchSixButton_OFF()
{
	auto Switch_SIX = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 69));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw6 = true;
			removeChildByTag(60);
			if (lv3.OR(lv3.sw6, lv3.sw7) == true && checked4_3 == false)
			{
				lv3.or1 = true;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == false)
				{
					lv3.not3 = false;
					SixOrSeven_ON();
				}
				checked4_3 = true;
			}
			SwitchSixButton_ON();
			break;
		}
	});
}

void Level_3::SwitchSevenButton_ON()
{
	auto Switch_SEVEN = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_SEVEN == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_SEVEN->setPosition(Vec2(60, 36));
		Switch_SEVEN->setTag(70);
		this->addChild(Switch_SEVEN, 1);
	}

	Switch_SEVEN->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw7 = false;
			if (lv3.OR(lv3.sw6, lv3.sw7) == false && checked4_3 == true)
			{
				lv3.or1 = false;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == true)
				{
					lv3.not3 = true;
					SixOrSeven_OFF();
				}
				checked4_3 = false;
			}
			SwitchSevenButton_OFF();
			break;
		}
	});
}

void Level_3::SwitchSevenButton_OFF()
{
	auto Switch_SEVEN = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SEVEN == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_SEVEN->setPosition(Vec2(60, 36));
		Switch_SEVEN->setTag(70);
		this->addChild(Switch_SEVEN, 1);
	}

	Switch_SEVEN->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv3.sw7 = true;
			if (lv3.OR(lv3.sw6, lv3.sw7) == true && checked4_3 == false)
			{
				lv3.or1 = true;
				removeChildByTag(5);
				if (lv3.NOT(lv3.or1) == false)
				{
					lv3.not3 = false;
					SixOrSeven_ON();
				}
				checked4_3 = true;
			}
			SwitchSevenButton_ON();
			break;
		}
	});
}

void Level_3::SixOrSeven_ON()
{
	if (lv3.NOT(lv3.not3) == true)
	{
		auto block5 = Sprite::create("Sprites/block.png");
		if (block5 == nullptr)
		{
			problemLoading("'block.png'");
		}
		else
		{
			block5->setPosition(Vec2(375, 52));
			block5->setTag(5);
			this->addChild(block5, 1);
		}

		auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
		block5->runAction(MoveBy);
	}
}

void Level_3::SixOrSeven_OFF()
{
	if (lv3.NOT(lv3.not3) == false)
	{
		auto block5 = Sprite::create("Sprites/block.png");
		if (block5 == nullptr)
		{
			problemLoading("'block.png'");
		}
		else
		{
			block5->setPosition(Vec2(420, 52));
			block5->setTag(5);
			this->addChild(block5, 1);
		}

		if (lv3.moved == true && lv3.moved1 == true && lv3.moved2 == true && lv3.moved3 == true)
		{
			removeChildByTag(71);
			auto coin = Sprite::create("Coin.png");
			if (coin == nullptr)
			{
				problemLoading("'Coin.png'");
			}
			else
			{
				coin->setPosition(Vec2(425, 78));
				coin->setTag(71);
				this->addChild(coin, 1);
			}

			auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -44));
			auto delay = DelayTime::create(0.5);
			auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
			coin->runAction(seq);

			this->schedule(schedule_selector(Level_3::NextLevel), 1.0f);
		}

		auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
		block5->runAction(MoveBy);
	}

}

void Level_3::RestartGame(float dt)
{
	c.IntCoins -= 1;
	if (c.IntCoins == 0)
	{
		stop = true;
		checked2_3 = checked3_3 = checked4_3 = falled1_3 = false;
		memset(&lv3, 0, sizeof(lv3));
		auto Menu = MenuBitcoinScene::createScene();
		Director::getInstance()->replaceScene(Menu);
	}

	if (stop == false && c.IntCoins > 0)
	{
		checked2_3 = checked3_3 = checked4_3 = falled1_3 = false;
		memset(&lv3, 0, sizeof(lv3));
		auto restart = Level_3::createScene();
		Director::getInstance()->replaceScene(restart);
	}
}

void Level_3::NextLevel(float dt)
{
	checked2_3 = checked3_3 = checked4_3 = falled1_3 = false;
	memset(&lv3, 0, sizeof(lv3));
	auto next = Level_4::createScene();
	Director::getInstance()->replaceScene(next);
}