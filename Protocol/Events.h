#pragma once

#include "ProtocolUtils.h"

namespace Protocol {
	class PROTOCOL_API KeyPressedEvent {
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}
