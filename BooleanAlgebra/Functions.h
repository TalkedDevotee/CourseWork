#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

struct functions
{
	bool sw1 = 0, sw2 = 0, sw3 = 0, sw4 = 0,
		sw5 = 0, sw6 = 0, sw7 = 0, not1 = 0,
		not2 = 0, not3 = 0, not4 = 0, and1 = 0,
		and2 = 0, and3 = 0, and4 = 0, or1 = 0,
		or2 = 0, or3 = 0, or4 = 0, or5 = 0,
		moved = 0, moved1 = 0, moved2 = 0, moved3 = 0;

	bool NOT(bool _sw)
	{
		if (_sw == false)
			return true;
		else
			return false;
	}

	bool AND(bool _sw1, bool _sw2)
	{
		if (_sw1 == true && _sw2 == true)
			return true;
		else
			return false;
	}

	bool OR(bool _sw1, bool _sw2)
	{
		if (_sw1 == true || _sw2 == true)
			return true;
		else
			return false;
	}
};

struct IntCoin
{
	int IntCoins = 0;
};

#endif