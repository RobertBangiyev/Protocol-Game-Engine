#pragma once

#include "ProtocolUtils.h"
#include "ProtocolApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

#define START_PROTOCOL_GAME(classname) \
int main()\
{\
	classname _protocol_game;\
	_protocol_game.Run();\
}