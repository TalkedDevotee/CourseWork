#include "MenuBitcoinScene.h"
#include "Level_4.h"
#include "ui\UIButton.h"
#include "BooleanAlgebra\Functions.h"

USING_NS_CC;

functions lv4;
extern struct IntCoin c;

extern bool stop;

bool checked2_4 = false; // "ИЛИ" от 1-ого и 2-ого выключателей
bool checked3_4 = false; // "И" от 1-ого и 3-его, 4-ого выключателей
bool checked5_4 = false; // "ИЛИ" от 1-ого и 6-ого, 7-ого выключателей
bool checked6_4 = false; //"И" от 1-ого и 5-ого выключателей
bool falled1_4 = false;

Scene* Level_4::createScene()
{
	return Level_4::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Level_4.cpp\n");
}

bool Level_4::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Sprites/Level_4/Background_level_4.png");
	if (sprite == nullptr)
	{
		problemLoading("'Background_level_4.png'");
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
		block2->setPosition(Vec2(420, 209));
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

	auto Coins = Label::createWithTTF("LEVEL 4", "fonts/bitcoin.ttf", 15);
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
			lv4.sw1 = true;
			if (lv4.NOT(lv4.sw1) == false)
			{
				lv4.not1 = false;
				if (lv4.NOT(lv4.not1) == true)
				{
					lv4.not2 = true;
					if (lv4.NOT(lv4.not2) == false)
					{
						lv4.not3 = false;
					}
				}
			}
			removeChildByTag(1);
			if (lv4.AND(lv4.sw1, lv4.sw2) == true && checked2_4 == false)
			{
				removeChildByTag(2);
				checked2_4 = true;
				OneOrTwo_ON();
			}
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			if (lv4.AND(lv4.sw1, lv4.sw5) == true && checked6_4 == false)
			{
				removeChildByTag(5);
				checked6_4 = true;
				OneAndFive_ON();
			}
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
			lv4.sw2 = true;
			if (lv4.AND(lv4.sw1, lv4.sw2) == true && checked2_4 == false)
			{
				removeChildByTag(2);
				checked2_4 = true;
				OneOrTwo_ON();
			}
			removeChildByTag(20);
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
			lv4.sw3 = true;
			if (lv4.AND(lv4.sw3, lv4.sw4) == true)
				lv4.and1 = true;
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			removeChildByTag(30);
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
			lv4.sw4 = true;
			if (lv4.AND(lv4.sw3, lv4.sw4) == true)
				lv4.and1 = true;
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			removeChildByTag(40);
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
			lv4.sw5 = true;
			if (lv4.AND(lv4.sw1, lv4.sw5) == true && checked6_4 == false)
			{
				removeChildByTag(5);
				checked6_4 = true;
				OneAndFive_ON();
			}
			removeChildByTag(50);
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
			lv4.sw6 = true;
			if (lv4.OR(lv4.sw6, lv4.sw7) == true)
				lv4.or1 = true;
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			removeChildByTag(60);
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
			lv4.sw7 = true;
			if (lv4.OR(lv4.sw6, lv4.sw7) == true)
				lv4.or1 = true;
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			removeChildByTag(70);
			SwitchSevenButton_ON();
			break;
		}
	});

	return true;
}

void Level_4::SwitchOneButton_ON()
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

	if (lv4.sw2 == true && lv4.moved == false && checked2_4 == true && checked3_4 == false && checked5_4 == true && checked6_4 == false)
	{
		removeChildByTag(71);
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

		auto MoveCoinBy = MoveBy::create(2.5, Vec2(0, -255));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_4::RestartGame), 3.0f);

		falled1_4 = true;
	}

	if (lv4.sw2 == true && lv4.moved == false && checked2_4 == true && checked3_4 == true && checked5_4 == true && checked6_4 == false)
	{
		removeChildByTag(71);
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

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -103));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_4 = true;

		this->schedule(schedule_selector(Level_4::RestartGame), 1.5f);
	}

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == true && checked6_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		falled1_4 = true;

		this->schedule(schedule_selector(Level_4::RestartGame), 1.5f);
	}

	if (lv4.moved == false && checked3_4 == false && checked5_4 == true && falled1_4 == false || lv4.moved == false && checked3_4 == true && checked5_4 == true && falled1_4 == false)
	{
		removeChildByTag(71);
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -54));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		lv4.moved = true;
	}

	if (lv4.moved == true && lv4.moved1 == false && checked2_4 == true && checked3_4 == true && checked5_4 == true && checked6_4 == false && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -49));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		lv4.moved1 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv4.sw1 = false;
			if (lv4.NOT(lv4.sw1) == true)
			{
				lv4.not1 = true;
				if (lv4.NOT(lv4.not1) == false)
				{
					lv4.not2 = false;
					if (lv4.NOT(lv4.not2) == true)
					{
						lv4.not3 = true;
					}
				}
			}
			removeChildByTag(1);
			if (lv4.AND(lv4.sw1, lv4.sw2) == false && checked2_4 == true)
			{
				removeChildByTag(2);
				checked2_4 = false;
				OneOrTwo_OFF();
			}
			if (lv4.AND(lv4.not2, lv4.and1) == false && checked3_4 == true)
			{
				removeChildByTag(3);
				checked3_4 = false;
				OneAndFour_OFF();
			}
			if (lv4.OR(lv4.sw1, lv4.or1) == false && checked5_4 == true)
			{
				removeChildByTag(4);
				checked5_4 = false;
				OneOrSeven_OFF();
			}
			if (lv4.AND(lv4.sw1, lv4.sw5) == false && checked6_4 == true)
			{
				removeChildByTag(5);
				checked6_4 = false;
				OneAndFive_OFF();
			}
			removeChildByTag(10);
			SwitchOneButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchOneButton_OFF()
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

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == false && checked3_4 == false && checked5_4 == false && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -51));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		lv4.moved2 = true;
	}

	if (lv4.moved == true && lv4.moved1 == false && checked2_4 == true && checked3_4 == false && checked5_4 == false && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -49));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		lv4.moved1 = true;
	}

	if (lv4.moved3 == true && checked5_4 == false && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -44));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_4::LevelsCompleted), 1.0f);
		this->schedule(schedule_selector(Level_4::GameOver), 4.0f);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv4.sw1 = true;
			if (lv4.NOT(lv4.sw1) == false)
			{
				lv4.not1 = false;
				if (lv4.NOT(lv4.not1) == true)
				{
					lv4.not2 = true;
					if (lv4.NOT(lv4.not2) == false)
					{
						lv4.not3 = false;
					}
				}
			}
			removeChildByTag(1);
			if (lv4.AND(lv4.sw1, lv4.sw2) == true && checked2_4 == false)
			{
				removeChildByTag(2);
				checked2_4 = true;
				OneOrTwo_ON();
			}
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			if (lv4.AND(lv4.sw1, lv4.sw5) == true && checked6_4 == false)
			{
				removeChildByTag(5);
				checked6_4 = true;
				OneAndFive_ON();
			}
			removeChildByTag(10);
			SwitchOneButton_ON();
			break;
		}
	});
}

void Level_4::SwitchTwoButton_ON()
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

	if (lv4.moved == true && lv4.moved1 == false && checked2_4 == true && checked3_4 == false && checked5_4 == true && checked6_4 == false)
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
			coin->setTag(2);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(2, Vec2(0, -201));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_4::RestartGame), 2.5f);

		falled1_4 = true;
	}

	if (lv4.moved == true && lv4.moved1 == false && checked2_4 == true && checked3_4 == true && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -49));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		lv4.moved1 = true;
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv4.sw2 = false;
			if (lv4.AND(lv4.sw1, lv4.sw2) == false && checked2_4 == true)
			{
				removeChildByTag(2);
				checked2_4 = false;
				OneOrTwo_OFF();
			}
			removeChildByTag(20);
			SwitchTwoButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchTwoButton_OFF()
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
			lv4.sw2 = true;
			if (lv4.AND(lv4.sw1, lv4.sw2) == true && checked2_4 == false)
			{
				removeChildByTag(2);
				checked2_4 = true;
				OneOrTwo_ON();
			}
			removeChildByTag(20);
			SwitchTwoButton_ON();
			break;
		}
	});
}

void Level_4::OneOrTwo_ON()
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

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block2->runAction(MoveBy);
}

void Level_4::OneOrTwo_OFF()
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

void Level_4::SwitchThreeButton_ON()
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
			lv4.sw3 = false;
			if (lv4.AND(lv4.sw3, lv4.sw4) == false)
				lv4.and1 = false;
			if (lv4.AND(lv4.not2, lv4.and1) == false && checked3_4 == true)
			{
				removeChildByTag(3);
				checked3_4 = false;
				OneAndFour_OFF();
			}
			removeChildByTag(30);
			SwitchThreeButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchThreeButton_OFF()
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
			lv4.sw3 = true;
			if (lv4.AND(lv4.sw3, lv4.sw4) == true)
				lv4.and1 = true;
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			removeChildByTag(30);
			SwitchThreeButton_ON();
			break;
		}
	});
}

void Level_4::SwitchFourButton_ON()
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
			lv4.sw4 = false;
			if (lv4.AND(lv4.sw3, lv4.sw4) == false)
				lv4.and1 = false;
			if (lv4.AND(lv4.not2, lv4.and1) == false && checked3_4 == true)
			{
				removeChildByTag(3);
				checked3_4 = false;
				OneAndFour_OFF();
			}
			removeChildByTag(40);
			SwitchFourButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchFourButton_OFF()
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
			lv4.sw4 = true;
			if (lv4.AND(lv4.sw3, lv4.sw4) == true)
				lv4.and1 = true;
			if (lv4.AND(lv4.not2, lv4.and1) == true && checked3_4 == false)
			{
				removeChildByTag(3);
				checked3_4 = true;
				OneAndFour_ON();
			}
			removeChildByTag(40);
			SwitchFourButton_ON();
			break;
		}
	});
}

void Level_4::OneAndFour_ON()
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

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block3->runAction(MoveBy);
}

void Level_4::OneAndFour_OFF()
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

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == false && lv4.moved3 == false && checked3_4 == false && checked5_4 == true && lv4.not3 == false && checked6_4 == false)
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

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -152));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_4 = true;

		this->schedule(schedule_selector(Level_4::RestartGame), 2.0f);
	}

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == false && lv4.moved3 == false && checked3_4 == false && checked5_4 == true && lv4.not3 == false && checked6_4 == true)
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

		falled1_4 = true;

		this->schedule(schedule_selector(Level_4::RestartGame), 1.5f);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block3->runAction(MoveBy);
}

void Level_4::SwitchFiveButton_ON()
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

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv4.sw5 = false;
			if (lv4.NOT(lv4.sw5) == true)
				lv4.not4 = true;
			if (lv4.AND(lv4.sw1, lv4.sw5) == false && checked6_4 == true)
			{
				removeChildByTag(5);
				checked6_4 = false;
				OneAndFive_OFF();
			}
			removeChildByTag(50);
			SwitchFiveButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchFiveButton_OFF()
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

	if (lv4.moved3 == true && checked5_4 == true && falled1_4 == false)
	{
		removeChildByTag(71);
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveBy = MoveBy::create(0.5, Vec2(0, -44));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_4::LevelsCompleted), 1.0f);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv4.sw5 = true;
			if (lv4.AND(lv4.sw1, lv4.sw5) == true && checked6_4 == false)
			{
				removeChildByTag(5);
				checked6_4 = true;
				OneAndFive_ON();
			}
			removeChildByTag(50);
			SwitchFiveButton_ON();
			break;
		}
	});
}

void Level_4::OneAndFive_ON()
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

void Level_4::OneAndFive_OFF()
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

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block5->runAction(MoveBy);
}

void Level_4::SwitchSixButton_ON()
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
			lv4.sw6 = false;
			if (lv4.OR(lv4.sw6, lv4.sw7) == false)
				lv4.or1 = false;
			if (lv4.OR(lv4.sw1, lv4.or1) == false && checked5_4 == true)
			{
				removeChildByTag(4);
				checked5_4 = false;
				OneOrSeven_OFF();
			}
			removeChildByTag(60);
			SwitchSixButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchSixButton_OFF()
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
			lv4.sw6 = true;
			if (lv4.OR(lv4.sw6, lv4.sw7) == true)
				lv4.or1 = true;
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			removeChildByTag(60);
			SwitchSixButton_ON();
			break;
		}
	});
}

void Level_4::SwitchSevenButton_ON()
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
			lv4.sw7 = false;
			if (lv4.OR(lv4.sw6, lv4.sw7) == false)
				lv4.or1 = false;
			if (lv4.OR(lv4.sw1, lv4.or1) == false && checked5_4 == true)
			{
				removeChildByTag(4);
				checked5_4 = false;
				OneOrSeven_OFF();
			}
			removeChildByTag(70);
			SwitchSevenButton_OFF();
			break;
		}
	});
}

void Level_4::SwitchSevenButton_OFF()
{
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
			lv4.sw7 = true;
			if (lv4.OR(lv4.sw6, lv4.sw7) == true)
				lv4.or1 = true;
			if (lv4.OR(lv4.sw1, lv4.or1) == true && checked5_4 == false)
			{
				removeChildByTag(4);
				checked5_4 = true;
				OneOrSeven_ON();
			}
			removeChildByTag(70);
			SwitchSevenButton_ON();
			break;
		}
	});
}

void Level_4::OneOrSeven_ON()
{
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

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == true && lv4.sw5 == true && checked6_4 == true)
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

		falled1_4 = true;

		this->schedule(schedule_selector(Level_4::RestartGame), 1.5f);
	}

	if (lv4.moved == true && lv4.moved1 == true && lv4.moved2 == true && lv4.moved3 == false && checked5_4 == true && checked6_4 == false && falled1_4 == false)
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

		lv4.moved3 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block4->runAction(MoveBy);
}

void Level_4::OneOrSeven_OFF()
{
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
}

void Level_4::RestartGame(float dt)
{
	c.IntCoins -= 1;
	if (c.IntCoins == 0)
	{
		stop = true;
		checked2_4 = checked3_4 = checked5_4 = checked6_4 = falled1_4 = false;
		memset(&lv4, 0, sizeof(lv4));
		auto Menu = MenuBitcoinScene::createScene();
		Director::getInstance()->replaceScene(Menu);
	}

	if (stop == false && c.IntCoins > 0)
	{
		checked2_4 = checked3_4 = checked5_4 = checked6_4 = falled1_4 = false;
		memset(&lv4, 0, sizeof(lv4));
		auto restart = Level_4::createScene();
		Director::getInstance()->replaceScene(restart);
	}
}

void Level_4::LevelsCompleted(float dt)
{
	auto Completed = Sprite::create("Sprites/Completed.png");
	if (Completed == nullptr)
	{
		problemLoading("'Completed.png'");
	}
	else
	{
		Completed->setPosition(Vec2(250, 170));
		this->addChild(Completed, 1);
	}
}

void Level_4::GameOver(float dt)
{
	checked2_4 = checked3_4 = checked5_4 = checked6_4 = falled1_4 = false;
	memset(&lv4, 0, sizeof(lv4));
	auto Menu = MenuBitcoinScene::createScene();
	Director::getInstance()->replaceScene(Menu);
}