#pragma once

#include "ProtocolUtils.h"
#include "ProtocolApp.h"

#define START_PROTOCOL_GAME(classname) \
int main()\
{\
	classname _protocol_game;\
	_protocol_game.Run();\
}