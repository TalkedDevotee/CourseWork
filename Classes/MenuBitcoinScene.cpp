#include "MenuBitcoinScene.h"
#include "Levels/Level_1.h"
#include "BooleanAlgebra/Functions.h"

USING_NS_CC;

IntCoin c;

bool stop = false;

Scene* MenuBitcoinScene::createScene()
{
	return MenuBitcoinScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuBitcoinScene.cpp\n");
}

bool MenuBitcoinScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	if (stop == true)
		stop = false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create("Exit.png", "Exit.png", CC_CALLBACK_1(MenuBitcoinScene::menuCloseCallback, this));
	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'Exit.png' and 'Exit.png'");
	}
	else
	{
		closeItem->setPosition(Vec2(430, 30));
	}

	auto playItem = MenuItemImage::create("Play.png", "Play.png", CC_CALLBACK_1(MenuBitcoinScene::menuStartCallBack, this));
	if (playItem == nullptr ||
		playItem->getContentSize().width <= 0 ||
		playItem->getContentSize().height <= 0)
	{
		problemLoading("'Play.png' and 'Play.png'");
	}
	else
	{
		playItem->setPosition(Vec2(48, 30));
	}

	auto exit = Menu::create(closeItem, NULL);
	auto play = Menu::create(playItem, NULL);

	exit->setPosition(Vec2::ZERO);
	play->setPosition(Vec2::ZERO);

	this->addChild(play, 1);
	this->addChild(exit, 1);

	auto sprite = Sprite::create("Background.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'Background.jpg'");
	}
	else
	{
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite, 0);
	}
	return true;
}

void MenuBitcoinScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void MenuBitcoinScene::menuStartCallBack(Ref* pSender)
{
	c.IntCoins = 4;
	auto start = Level_1::createScene();
	Director::getInstance()->replaceScene(start);
}