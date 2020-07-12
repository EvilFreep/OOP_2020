#pragma once
#include <iostream>
#include <string>
#include "TVset.h"

using namespace std;

const string TURN_ON_COM = "TurnOn";
const string TURN_OFF_COM = "TurnOff";
const string TV_SET_ON_MES = "TV is turned on\n";
const string TV_SET_OFF_MES = "TV is turned off\n";
const string TV_ALREADY_ON_MES = "TV is already on\n";
const string TV_ALREADY_OFF_MES = "TV is already off\n";
const string SELECT_CHANNEL_COM = "SelectChannel";
const string CHANNEL_NOT_EXIST_MES = "This channel is not exist\n";
const string SELECT_CHANNEL_MES = "Selected channel is ";
const string INFO_COM = "Info";
const string CURRENT_CHANNEL_MES = "Current channel is ";
const string UNKNOWN_COMMAND_MES = "Unknown command\nUsage:\n\tTurnOn\n\tTurnOff\n\tSelectChannel <channel>\n\tInfo\n";


void Interfacer(CTVSet& TV, istream& input, ostream& output);