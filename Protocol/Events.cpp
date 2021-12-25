#include "pch.h"

#include "Events.h"

Protocol::KeyPressedEvent::KeyPressedEvent(int keyCode): mKeyCode(keyCode)
{
}

int Protocol::KeyPressedEvent::GetKeyCode() const
{
	return mKeyCode;
}
