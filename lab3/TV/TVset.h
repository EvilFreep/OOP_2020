#pragma once
#include <iostream>
#include <string>

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int currentChannel);
	int GetChannel() const;
	bool IsExist(int currentChannel);
	bool IsTurnOn() const;

private:
	bool isEnable = false;
	int channel = 1;
	static const int minChannel = 1;
	static const int maxChannel = 99;
};