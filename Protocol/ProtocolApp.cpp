#include "pch.h"
#include "ProtocolApp.h"
#include <GLFW/glfw3.h>

namespace Protocol {
	void ProtocolApp::Run() {
		std::cout << "Protocol is running..." << std::endl;


		mGameWindow.CreateWindow(800, 600, "Test");

		while (true) {
			OnUpdate();

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();
		}
	}

	void ProtocolApp::OnUpdate() {

	}

	ProtocolApp::ProtocolApp() {
	}
}