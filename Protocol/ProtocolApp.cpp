#include "pch.h"
#include "ProtocolApp.h"

namespace Protocol {
	void ProtocolApp::Run() {
		std::cout << "Protocol is running..." << std::endl;
		while (true) {
			OnUpdate();
		}
	}

	void ProtocolApp::OnUpdate() {

	}

	ProtocolApp::ProtocolApp() {

	}
}