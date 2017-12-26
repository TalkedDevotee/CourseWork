#include "MenuBitcoinScene.h"
#include "Level_2.h"
#include "Level_3.h"
#include "ui\UIButton.h"
#include "BooleanAlgebra\Functions.h"

USING_NS_CC;

functions lv2;
extern struct IntCoin c;

extern bool stop;

bool checked2_2 = false; // 2-ой и 3-ий выключатели
bool checked3_2 = false; // 1-ый и 4-ый выключатели
bool checked5_2 = false; // 4-ый и 5-ый выключатели
bool falled1_2;

Scene* Level_2::createScene()
{
	return Level_2::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Level_2.cpp\n");
}

bool Level_2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Sprites/Level_2/Background_level_2.png");
	if (sprite == nullptr)
	{
		problemLoading("'Background_level_2.png'");
	}
	else
	{
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(sprite, 0);
	}

	auto coin = Sprite::create("Sprites/Coin.png");
	if (coin == nullptr)
	{
		problemLoading("'Coin.png'");
	}
	else
	{
		coin->setPosition(Vec2(425, 267));
		coin->setTag(70);
		this->addChild(coin, 1);
	}

	auto Coins = Label::createWithTTF("LEVEL 2", "fonts/bitcoin.ttf", 15);
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

	auto block = Sprite::create("Sprites/block.png");
	if (block == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block->setPosition(Vec2(420, 241));
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
		block2->setPosition(Vec2(420, 183));
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
		block3->setPosition(Vec2(420, 125));
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
		block4->setPosition(Vec2(420, 68));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto Switch_ONE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 241));
		Switch_ONE->setTag(10);
		this->addChild(Switch_ONE, 1);
	}

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw1 = true;
			removeChildByTag(1);
			removeChildByTag(10);
			removeChildByTag(90);
			removeChildByTag(91);
			if (lv2.OR(lv2.sw1, lv2.sw4) == true && checked3_2 == false)
			{
				removeChildByTag(3);
				OneOrFour_ON();
				checked3_2 = true;
			}
			SwitchOneButton_ON();
			break;
		}
	});

	auto Switch_TWO = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 200));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw2 = true;
			if (lv2.AND(lv2.sw2, lv2.sw3) == true)
			{
				removeChildByTag(2);
				TwoAndThree_ON();
				checked2_2 = true;
			}
			removeChildByTag(20);
			SwitchTwoButton_ON();
			break;
		}
	});

	auto Switch_THREE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 167));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw3 = true;
			if (lv2.AND(lv2.sw2, lv2.sw3) == true)
			{
				removeChildByTag(2);
				TwoAndThree_ON();
				checked2_2 = true;
			}
			removeChildByTag(30);
			SwitchThreeButton_ON();
			break;
		}
	});

	auto Switch_FOUR = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 108));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw4 = true;
			removeChildByTag(40);
			removeChildByTag(92);
			if (lv2.OR(lv2.sw1, lv2.sw4) == true && checked3_2 == false)
			{
				removeChildByTag(3);
				OneOrFour_ON();
				checked3_2 = true;
			}
			if (lv2.OR(lv2.sw4, lv2.sw5) == true && checked5_2 == false)
			{
				removeChildByTag(4);
				FourOrFive_ON();
				checked5_2 = true;
			}
			SwitchFourButton_ON();
			break;
		}
	});

	auto Switch_FIVE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 52));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw5 = true;
			removeChildByTag(50);
			if (lv2.OR(lv2.sw4, lv2.sw5) == true && checked5_2 == false)
			{
				removeChildByTag(4);
				FourOrFive_ON();
				checked5_2 = true;
			}
			SwitchFiveButton_ON();
			break;
		}
	});

	return true;
}

void Level_2::SwitchOneButton_ON()
{
	auto Switch_ONE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 241));
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
		block->setPosition(Vec2(420, 241));
		block->setTag(1);
		this->addChild(block, 1);
	}

	auto coin = Sprite::create("Coin.png");
	if (lv2.moved == false && checked2_2 == true && checked3_2 == true && checked5_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 267));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -173));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_2 = true;

		this->schedule(schedule_selector(Level_2::RestartGame), 2.0f);
	}

	if (lv2.moved == false && checked2_2 == true && checked3_2 == true && checked5_2 == true)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 267));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(2, Vec2(0, -233));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_2 = true;

		this->schedule(schedule_selector(Level_2::RestartGame), 2.5f);
	}

	if (lv2.moved == false && checked2_2 == false && checked3_2 == true && checked5_2 == false && falled1_2 == false || lv2.moved == false && checked2_2 == false && checked3_2 == true && checked5_2 == true && falled1_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 267));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -58));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv2.moved = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw1 = false;
			removeChildByTag(1);
			removeChildByTag(10);
			if (lv2.OR(lv2.sw1, lv2.sw4) == false && checked3_2 == true)
			{
				removeChildByTag(3);
				OneOrFour_OFF();
				checked3_2 = false;
			}
			SwitchOneButton_OFF();
			break;
		}
	});
}

void Level_2::SwitchOneButton_OFF()
{
	auto Switch_ONE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_ONE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_ONE->setPosition(Vec2(60, 241));
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
		block->setPosition(Vec2(375, 241));
		block->setTag(1);
		this->addChild(block, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	
	block->runAction(MoveBy);

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw1 = true;
			removeChildByTag(1);
			removeChildByTag(10);
			if (lv2.OR(lv2.sw1, lv2.sw4) == true && checked3_2 == false)
			{
				removeChildByTag(3);
				OneOrFour_ON();
				checked3_2 = true;
			}
			SwitchOneButton_ON();
			break;
		}
	});
}

void Level_2::SwitchTwoButton_ON()
{
	auto Switch_TWO = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 200));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw2 = false;
			if (checked2_2 == true)
			{
				checked2_2 = false;
				removeChildByTag(2);
				TwoAndThree_OFF();
			}
			removeChildByTag(20);
			SwitchTwoButton_OFF();
			break;
		}
	});
}

void Level_2::SwitchTwoButton_OFF()
{
	auto Switch_TWO = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_TWO == nullptr)
	{
		problemLoading("'OFF.png'");
	}
	else
	{
		Switch_TWO->setPosition(Vec2(60, 200));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw2 = true;
			if (lv2.AND(lv2.sw2, lv2.sw3) == true && checked2_2 == false)
			{
				checked2_2 = true;
				removeChildByTag(2);
				TwoAndThree_ON();
			}
			removeChildByTag(20);
			SwitchTwoButton_ON();
			break;
		}
	});
}

void Level_2::SwitchThreeButton_ON()
{
	auto Switch_THREE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 167));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw3 = false;
			if (checked2_2 == true)
			{
				checked2_2 = false;
				removeChildByTag(2);
				TwoAndThree_OFF();
			}
			removeChildByTag(30);
			SwitchThreeButton_OFF();
			break;
		}
	});
}

void Level_2::SwitchThreeButton_OFF()
{
	auto Switch_THREE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_THREE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_THREE->setPosition(Vec2(60, 167));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw3 = true;
			if (lv2.AND(lv2.sw2, lv2.sw3) == true && checked2_2 == false)
			{
				checked2_2 = true;
				removeChildByTag(2);
				TwoAndThree_ON();
			}
			removeChildByTag(30);
			SwitchThreeButton_ON();
			break;
		}
	});
}

void Level_2::TwoAndThree_ON()
{
	auto block2 = Sprite::create("Sprites/block.png");
	if (block2 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block2->setPosition(Vec2(420, 183));
		block2->setTag(2);
		this->addChild(block2, 1);
	}

	auto coin = Sprite::create("Coin.png");
	if (lv2.moved == true && lv2.moved1 == false && checked3_2 == true && checked5_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 209));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -115));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_2 = true;

		this->schedule(schedule_selector(Level_2::RestartGame), 1.5f);
	}

	if (lv2.moved == true && lv2.moved1 == false && checked3_2 == true && checked5_2 == true)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 209));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(1.5, -175));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_2 = true;

		this->schedule(schedule_selector(Level_2::RestartGame), 1.5f);
	}

	if (lv2.moved == true && lv2.moved1 == false && checked3_2 == false && checked5_2 == false && falled1_2 == false || lv2.moved == true && lv2.moved1 == false && checked3_2 == false && checked5_2 == true && falled1_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 209));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -58));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv2.moved1 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block2->runAction(MoveBy);
}

void Level_2::TwoAndThree_OFF()
{
	auto block2 = Sprite::create("Sprites/block.png");
	if (block2 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block2->setPosition(Vec2(375, 183));
		block2->setTag(2);
		this->addChild(block2, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block2->runAction(MoveBy);
}

void Level_2::SwitchFourButton_ON()
{
	auto Switch_FOUR = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 108));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw4 = false;
			removeChildByTag(40);
			if (lv2.OR(lv2.sw1, lv2.sw4) == false && checked3_2 == true)
			{
				removeChildByTag(3);
				OneOrFour_OFF();
				checked3_2 = false;
			}
			if (lv2.OR(lv2.sw4, lv2.sw5) == false && checked5_2 == true)
			{
				removeChildByTag(4);
				FourOrFive_OFF();
				checked5_2 = false;
			}
			SwitchFourButton_OFF();
			break;
		}
	});
}

void Level_2::SwitchFourButton_OFF()
{
	auto Switch_FOUR = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 108));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw4 = true;
			removeChildByTag(40);
			if (lv2.OR(lv2.sw1, lv2.sw4) == true && checked3_2 == false)
			{
				removeChildByTag(3);
				OneOrFour_ON();
				checked3_2 = true;
			}
			if (lv2.OR(lv2.sw4, lv2.sw5) == true && checked5_2 == false)
			{
				removeChildByTag(4);
				FourOrFive_ON();
				checked5_2 = true;
			}
			SwitchFourButton_ON();
			break;
		}
	});
}

void Level_2::OneOrFour_ON()
{
	auto block3 = Sprite::create("Sprites/block.png");
	if (block3 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block3->setPosition(Vec2(420, 125));
		block3->setTag(3);
		this->addChild(block3, 1);
	}

	auto coin = Sprite::create("Coin.png");
	if (lv2.moved == true && lv2.moved1 == true && lv2.moved2 == false && checked5_2 == true)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 151));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -117));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1_2 = true;

		this->schedule(schedule_selector(Level_2::RestartGame), 1.5f);
	}

	if (lv2.moved == true && lv2.moved1 == true && lv2.moved2 == false && checked5_2 == false && falled1_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 151));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -57));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		lv2.moved2 = true;
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block3->runAction(MoveBy);
}

void Level_2::OneOrFour_OFF()
{
	auto block3 = Sprite::create("Sprites/block.png");
	if (block3 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block3->setPosition(Vec2(375, 125));
		block3->setTag(3);
		this->addChild(block3, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block3->runAction(MoveBy);
}

void Level_2::SwitchFiveButton_ON()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 52));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw5 = false;
			removeChildByTag(50);
			if (lv2.OR(lv2.sw4, lv2.sw5) == false && checked5_2 == true)
			{
				removeChildByTag(4);
				FourOrFive_OFF();
				checked5_2 = false;
			}
			SwitchFiveButton_OFF();
			break;
		}
	});
}

void Level_2::SwitchFiveButton_OFF()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 52));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv2.sw5 = true;
			removeChildByTag(50);
			if (lv2.OR(lv2.sw4, lv2.sw5) == true && checked5_2 == false)
			{
				removeChildByTag(4);
				FourOrFive_ON();
				checked5_2 = true;
			}
			SwitchFiveButton_ON();
			break;
		}
	});
}

void Level_2::FourOrFive_ON()
{
	auto block4 = Sprite::create("Sprites/block.png");
	if (block4 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block4->setPosition(Vec2(420, 68));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto coin = Sprite::create("Coin.png");
	if (lv2.sw5 == false && lv2.moved == true && lv2.moved1 == true && lv2.moved2 == true && falled1_2 == false)
	{
		removeChildByTag(70);
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 94));
			coin->setTag(70);
			this->addChild(coin, 1);
		}

		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -60));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_2::NextLevel), 1.0f);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block4->runAction(MoveBy);
}

void Level_2::FourOrFive_OFF()
{
	auto block4 = Sprite::create("Sprites/block.png");
	if (block4 == nullptr)
	{
		problemLoading("'block.png'");
	}
	else
	{
		block4->setPosition(Vec2(375, 68));
		block4->setTag(4);
		this->addChild(block4, 1);
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block4->runAction(MoveBy);
}

void Level_2::RestartGame(float dt)
{
	c.IntCoins -= 1;
	if (c.IntCoins == 0)
	{
		stop = true;
		checked2_2 = checked3_2 = checked5_2 = falled1_2 = false;
		memset(&lv2, 0, sizeof(lv2));
		auto Menu = MenuBitcoinScene::createScene();
		Director::getInstance()->replaceScene(Menu);
	}

	if (stop == false && c.IntCoins > 0)
	{
		checked2_2 = checked3_2 = checked5_2 = falled1_2 = false;
		memset(&lv2, 0, sizeof(lv2));
		auto restart = Level_2::createScene();
		Director::getInstance()->replaceScene(restart);
	}
}

void Level_2::NextLevel(float dt)
{
	checked2_2 = checked3_2 = checked5_2 = falled1_2 = false;
	memset(&lv2, 0, sizeof(lv2));
	auto next = Level_3::createScene();
	Director::getInstance()->replaceScene(next);
}