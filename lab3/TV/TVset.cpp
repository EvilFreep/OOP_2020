#include "TVset.h"

void CTVSet::TurnOn()
{
	isEnable = true;
}

void CTVSet::TurnOff()
{
	isEnable = false;
}

bool CTVSet::SelectChannel(int currentChannel)
{
	if (!isEnable)
	{
		return false;
	}
	else if (IsExist(currentChannel))
	{
		channel = currentChannel;
		return true;
	}
	return false;
}

bool CTVSet::IsTurnOn() const
{
	return isEnable;
}

bool CTVSet::IsExist(int currentChannel)
{
	return currentChannel <= maxChannel && currentChannel >= minChannel;
}

int CTVSet::GetChannel() const
{
	if (isEnable)
		return channel;
	return 0;
}