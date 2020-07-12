#include "TVInterface.h"

void TurnOn(CTVSet& TV, ostream& output)
{
	if (!TV.IsTurnOn())
	{
		TV.TurnOn();
		output << TV_SET_ON_MES;
	}
	else
	{
		output << TV_ALREADY_ON_MES;
	}
}

void TurnOff(CTVSet& TV, ostream& output)
{
	if (TV.IsTurnOn())
	{
		TV.TurnOff();
		output << TV_SET_OFF_MES;
	}
	else
	{
		output << TV_ALREADY_OFF_MES;
	}
}

void SelectChannel(CTVSet& TV, ostream& output, istream& input)
{
	int channel;
	if (input >> channel)
	{
		if (!TV.IsTurnOn())
		{
			output << TV_SET_OFF_MES;
		}
		else
		{
			if (!TV.IsExist(channel))
			{
				output << CHANNEL_NOT_EXIST_MES;
				return;
			}

			TV.SelectChannel(channel);
			output << SELECT_CHANNEL_MES << channel << endl;
		}
	}
}

void Info(CTVSet& TV, ostream& output)
{
	if (TV.IsTurnOn())
	{
		output << TV_SET_ON_MES;
		output << CURRENT_CHANNEL_MES << TV.GetChannel() << endl;
	}
	else
	{
		output << TV_SET_OFF_MES;
	}
}

void Interfacer(CTVSet& TV, istream& input, ostream& output)
{
std::string command;
	while (input >> command)
	{
		if (command == TURN_ON_COM)
		{
			TurnOn(TV, output);
		}
		else if (command == TURN_OFF_COM)
		{
			TurnOff(TV, output);
		}
		else if (command == SELECT_CHANNEL_COM)
		{
			SelectChannel(TV, output, input);
		}
		else if (command == INFO_COM)
		{
			Info(TV, output);
		}
		else
		{
			output << UNKNOWN_COMMAND_MES;
		}
	}
}