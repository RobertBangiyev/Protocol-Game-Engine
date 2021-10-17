#include "Protocol.h"

class MyGameApp : public Protocol::ProtocolApp {
	void OnUpdate() override {

	}
};

START_PROTOCOL_GAME(MyGameApp);