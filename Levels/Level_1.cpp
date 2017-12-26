#include "MenuBitcoinScene.h"
#include "Level_1.h"
#include "Level_2.h"
#include "ui/CocosGUI.h"
#include "BooleanAlgebra\Functions.h"

USING_NS_CC;

functions lv1;
extern struct IntCoin c;

bool checked2 = false; // 2-ой и 3-ий выключатели
bool checked5 = false; // 5-ый и 6-ой выключатели

bool falled1 = false;

extern bool stop;

Scene* Level_1::createScene()
{
	return Level_1::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Level_1.cpp\n");
}

bool Level_1::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Sprites/Level_1/Background_level_1.png");
	if (sprite == nullptr)
	{
		problemLoading("'Background_level_1.png'");
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

	auto Coins = Label::createWithTTF("LEVEL 1", "fonts/bitcoin.ttf", 15);
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
		Switch_ONE->setPosition(Vec2(60, 241));
		Switch_ONE->setTag(10);
		this->addChild(Switch_ONE, 1);
	}

	Switch_ONE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw1 = false;
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
		Switch_TWO->setPosition(Vec2(60, 200));
		Switch_TWO->setTag(20);
		this->addChild(Switch_TWO, 1);
	}

	Switch_TWO->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw2 = true;
			if (lv1.AND(lv1.sw2, lv1.sw3) == true)
			{
				removeChildByTag(2);
				TwoAndTrhee_ON();
				checked2 = true;
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
		Switch_THREE->setPosition(Vec2(60, 167));
		Switch_THREE->setTag(30);
		this->addChild(Switch_THREE, 1);
	}

	Switch_THREE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw3 = true;
			if (lv1.AND(lv1.sw2, lv1.sw3) == true)
			{
				removeChildByTag(2);
				TwoAndTrhee_ON();
				checked2 = true;
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
		Switch_FOUR->setPosition(Vec2(60, 125));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw4 = true;
			removeChildByTag(3);
			removeChildByTag(40);
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
		Switch_FIVE->setPosition(Vec2(60, 85));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw5 = true;
			if (lv1.OR(lv1.sw5, lv1.sw6) == true && checked5 == false)
			{
				removeChildByTag(4);
				FiveOrSix_ON();
				checked5 = true;
			}
			removeChildByTag(50);
			SwitchFiveButton_ON();
			break;
		}
	});

	auto Switch_SIX = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 53));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw6 = true;
			if (lv1.OR(lv1.sw5, lv1.sw6) == true && checked5 == false)
			{
				removeChildByTag(4);
				FiveOrSix_ON();
				checked5 = true;
			}
			removeChildByTag(60);
			SwitchSixButton_ON();
			break;
		}
	});

	return true;
}

void Level_1::SwitchOneButton_ON()
{
	if (lv1.moved == false && lv1.moved1 == false && lv1.moved2 == false)
		removeChildByTag(70);

	if (checked2 == true && lv1.sw4 == false && lv1.sw5 == false && lv1.sw6 == false || checked2 == true && lv1.sw4 == false && lv1.sw5 == true && lv1.sw6 == false || checked2 == true && lv1.sw4 == false && lv1.sw5 == false && lv1.sw6 == true || checked2 == true && lv1.sw4 == false && lv1.sw5 == true && lv1.sw6 == true)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 267));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}

		auto MoveCoinBy = MoveBy::create(1, Vec2(0, -116));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1 = true;

		this->schedule(schedule_selector(Level_1::RestartGame), 1.5f);
	}

	if (checked2 == true && lv1.sw4 == true && lv1.sw5 == false && lv1.sw6 == false)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 267));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -173));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1 = true;

		this->schedule(schedule_selector(Level_1::RestartGame), 2.0f);
	}

	if (checked2 == true && lv1.sw4 == true && lv1.sw5 == true  && lv1.sw6 == false || checked2 == true && lv1.sw4 == true && lv1.sw5 == false && lv1.sw6 == true || checked2 == true && lv1.sw4 == true && lv1.sw5 == true && lv1.sw6 == true)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 267));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}

		auto MoveCoinBy = MoveBy::create(2, Vec2(0, -233));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		this->schedule(schedule_selector(Level_1::RestartGame), 2.5f);
	}

	auto Switch_ONE_ON = ui::Button::create("Buttons_labels/ON.png", "Buttons_labesl/OFF.png");
	if (Switch_ONE_ON == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_ONE_ON->setPosition(Vec2(60, 241));
		Switch_ONE_ON->setTag(10);
		this->addChild(Switch_ONE_ON, 1);
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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == false && checked2 == false)
	{
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 267));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}
	}
	
	if (lv1.moved == true && checked2 == false)
	{
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 209));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));

	if (lv1.NOT(lv1.sw1) == true)
	{
		lv1.not1 = true;
		if (lv1.NOT(lv1.not1) == false)
		{
			lv1.not1 = false;
			if (lv1.NOT(lv1.not1) == true)
			{
				block->runAction(MoveBy);
				if (lv1.moved == false && lv1.moved1 == false && lv1.moved2 == false && checked2 == false)
				{
					auto MoveCoin = MoveBy::create(0.7, Vec2(0, -58));
					auto delay = DelayTime::create(0.5);
					auto seq = Sequence::create(delay, MoveCoin, nullptr);
					coin->runAction(seq);
					lv1.moved = true;
				}
			}
		}
	}

	Switch_ONE_ON->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			removeChildByTag(1);
			removeChildByTag(10);
			if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false)
				removeChildByTag(70);
			lv1.sw1 = true;
			SwitchOneButton_OFF();
			break;
		}
	});

}

void Level_1::SwitchOneButton_OFF()
{
	if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false)
		removeChildByTag(70);

	auto Switch_ONE_OFF = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_ONE_OFF == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_ONE_OFF->setPosition(Vec2(60, 241));
		Switch_ONE_OFF->setTag(10);
		this->addChild(Switch_ONE_OFF, 1);
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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true)
	{
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			if (lv1.moved1 == false)
			{
				coin->setPosition(Vec2(425, 209));
				coin->setTag(70);
				this->addChild(coin, 1);
			}
		}
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));

	if (lv1.NOT(lv1.sw1) == false)
	{
		lv1.not1 = false;
		if (lv1.NOT(lv1.not1) == true)
		{
			lv1.not1 = true;
			if (lv1.NOT(lv1.not1) == false)
				block->runAction(MoveBy);
		}
	}

	Switch_ONE_OFF->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			removeChildByTag(1);
			removeChildByTag(10);
			if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false)
				removeChildByTag(70);
			lv1.sw1 = false;
			SwitchOneButton_ON();
			break;
		}
	});
}

void Level_1::SwitchTwoButton_ON()
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
			lv1.sw2 = false;
			if (checked2 == true)
			{
				checked2 = false;
				removeChildByTag(2);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
					removeChildByTag(70);
				TwoAndTrhee_OFF();
			}
			removeChildByTag(20);
			SwitchTwoButton_OFF();
			break;
		}
	});
}


void Level_1::SwitchTwoButton_OFF()
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
			lv1.sw2 = true;
			if (lv1.AND(lv1.sw2, lv1.sw3) == true && checked2 == false)
			{
				checked2 = true;
				removeChildByTag(2);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
				removeChildByTag(70);
				TwoAndTrhee_ON();
			}
			removeChildByTag(20);
			SwitchTwoButton_ON();
			break;
		}
	});
}

void Level_1::SwitchThreeButton_ON()
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
			lv1.sw3 = false;
			if (checked2 == true)
			{
				checked2 = false;
				removeChildByTag(2);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
					removeChildByTag(70);
				TwoAndTrhee_OFF();
			}
			removeChildByTag(30);
			SwitchThreeButton_OFF();
			break;
		}
	});
}


void Level_1::SwitchThreeButton_OFF()
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
			lv1.sw3 = true;
			if (lv1.AND(lv1.sw2, lv1.sw3) == true && checked2 == false)
			{
				checked2 = true;
				removeChildByTag(2);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true)
				removeChildByTag(70);
				TwoAndTrhee_ON();
			}
			removeChildByTag(30);
			SwitchThreeButton_ON();
			break;
		}
	});
}

void Level_1::TwoAndTrhee_ON()
{
	if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false)
		removeChildByTag(70);

	if (lv1.sw4 == true && lv1.sw5 == false && lv1.sw6 == false && lv1.moved == true)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
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

		falled1 = true;

		this->schedule(schedule_selector(Level_1::RestartGame), 1.5f);
	}

	if (lv1.sw4 == true && lv1.sw5 == true && lv1.sw6 == false && lv1.moved == true || lv1.sw4 == true && lv1.sw5 == false && lv1.sw6 == true && lv1.moved == true || lv1.sw4 == true && lv1.sw5 == true && lv1.sw6 == true && lv1.moved == true)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
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

		auto MoveCoinBy = MoveBy::create(1.5, Vec2(0, -175));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);

		falled1 = true;

		this->schedule(schedule_selector(Level_1::RestartGame), 2.0f);
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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false && falled1 == false)
	{
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
	}

	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false && falled1 == false)
	{
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
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block2->runAction(MoveBy);

	if (lv1.moved == true && lv1.moved1 == false && lv1.moved2 == false)
	{
		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -58));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);
		lv1.moved1 = true;
	}
}

void Level_1::TwoAndTrhee_OFF()
{
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
		removeChildByTag(70);

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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
	{
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
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block2->runAction(MoveBy);
}

void Level_1::SwitchFourButton_ON()
{
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false)
		removeChildByTag(70);

	if (lv1.sw5 == true && lv1.sw6 == false && lv1.moved1 == true || lv1.sw5 == false && lv1.sw6 == true && lv1.moved1 == true || lv1.sw5 == true && lv1.sw6 == true && lv1.moved1 == true)
	{
		auto coin = Sprite::create("Sprites/Coin.png");
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

		falled1 = true;

		this->schedule(schedule_selector(Level_1::RestartGame), 1.5f);
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

	auto Switch_FOUR = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'ON.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 125));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false && falled1 == false)
	{
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
	}

	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && falled1 == false)
	{
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
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));

	if (lv1.NOT(lv1.sw4) == false)
		block3->runAction(MoveBy);

	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == false && falled1 == false)
	{
		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -57));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy,  nullptr);
		coin->runAction(seq);
		lv1.moved2 = true;
	}

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw4 = false;
			removeChildByTag(3);
			removeChildByTag(40);
			if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true)
				removeChildByTag(70);
			SwitchFourButton_OFF();
			break;
		}
	});
}

void Level_1::SwitchFourButton_OFF()
{
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true)
		removeChildByTag(70);

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

	auto Switch_FOUR = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FOUR == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FOUR->setPosition(Vec2(60, 125));
		Switch_FOUR->setTag(40);
		this->addChild(Switch_FOUR, 1);
	}

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true)
	{
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
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));

	if (lv1.NOT(lv1.sw4) == true)
		block3->runAction(MoveBy);

	Switch_FOUR->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw4 = true;
			removeChildByTag(3);
			removeChildByTag(40);
			if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true)
				removeChildByTag(70);
			SwitchFourButton_ON();
			break;
		}
	});
}

void Level_1::SwitchFiveButton_ON()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 85));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw5 = false;
			if (lv1.sw6 == false && checked5 == true)
			{
				removeChildByTag(4);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
					removeChildByTag(70);
				FiveOrSix_OFF();
				checked5 = false;
			}
			removeChildByTag(50);
			SwitchFiveButton_OFF();
			break;
		}
	});
}

void Level_1::SwitchFiveButton_OFF()
{
	auto Switch_FIVE = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_FIVE == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_FIVE->setPosition(Vec2(60, 85));
		Switch_FIVE->setTag(50);
		this->addChild(Switch_FIVE, 1);
	}

	Switch_FIVE->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw5 = true;
			if (lv1.sw6 == false && checked5 == false)
			{
				removeChildByTag(4);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
					removeChildByTag(70);
				FiveOrSix_ON();
				checked5 = true;
			}
			removeChildByTag(50);
			SwitchFiveButton_ON();
			break;
		}
	});
}

void Level_1::SwitchSixButton_ON()
{
	auto Switch_SIX = ui::Button::create("Buttons_labels/ON.png", "Buttons_labels/OFF.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'ON.png and OFF.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 53));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw6 = false;
			if (lv1.sw5 == false && checked5 == true)
			{
				removeChildByTag(4);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
					removeChildByTag(70);
				FiveOrSix_OFF();
				checked5 = false;
			}
			removeChildByTag(60);
			SwitchSixButton_OFF();
			break;
		}
	});
}

void Level_1::SwitchSixButton_OFF()
{
	auto Switch_SIX = ui::Button::create("Buttons_labels/OFF.png", "Buttons_labels/ON.png");
	if (Switch_SIX == nullptr)
	{
		problemLoading("'OFF.png and ON.png'");
	}
	else
	{
		Switch_SIX->setPosition(Vec2(60, 53));
		Switch_SIX->setTag(60);
		this->addChild(Switch_SIX, 1);
	}

	Switch_SIX->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::ENDED:
			lv1.sw6 = true;
			if (lv1.sw5 == false && checked5 == false)
			{
				removeChildByTag(4);
				if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
					removeChildByTag(70);
				FiveOrSix_ON();
				checked5 = true;
			}
			removeChildByTag(60);
			SwitchSixButton_ON();
			break;
		}
	});
}

void Level_1::FiveOrSix_ON()
{
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == false)
		removeChildByTag(70);

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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == false)
	{
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
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(-45, 0));
	block4->runAction(MoveBy);

	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == false)
	{
		auto MoveCoinBy = MoveBy::create(0.5, Vec2(0, -60));
		auto delay = DelayTime::create(0.5);
		auto seq = Sequence::create(delay, MoveCoinBy, nullptr);
		coin->runAction(seq);
		lv1.moved3 = true;

		this->schedule(schedule_selector(Level_1::NextLevel), 1.0f);
	}
}

void Level_1::FiveOrSix_OFF()
{
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
		removeChildByTag(70);

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

	auto coin = Sprite::create("Sprites/Coin.png");
	if (lv1.moved == true && lv1.moved1 == true && lv1.moved2 == true && lv1.moved3 == true)
	{
		if (coin == nullptr)
		{
			problemLoading("'Coin.png'");
		}
		else
		{
			coin->setPosition(Vec2(425, 34));
			coin->setTag(70);
			this->addChild(coin, 1);
		}
	}

	auto MoveBy = MoveBy::create(0.5, Vec2(45, 0));
	block4->runAction(MoveBy);
}

void Level_1::RestartGame(float dt)
{
	c.IntCoins -= 1;
	if (c.IntCoins == 0)
	{
		stop = true;
		checked2 = checked5 = falled1 = false;
		memset(&lv1, 0, sizeof(lv1));
		auto Menu = MenuBitcoinScene::createScene();
		Director::getInstance()->replaceScene(Menu);
	}
	
	if (stop == false && c.IntCoins > 0)
	{
		checked2 = checked5 = falled1 = false;
		memset(&lv1, 0, sizeof(lv1));
		auto restart = Level_1::createScene();
		Director::getInstance()->replaceScene(restart);
	}
}

void Level_1::NextLevel(float dt)
{
	checked2 = checked5 = falled1 = false;
	memset(&lv1, 0, sizeof(lv1));
	auto next = Level_2::createScene();
	Director::getInstance()->replaceScene(next);
}