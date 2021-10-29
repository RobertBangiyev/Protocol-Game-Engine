#pragma once
#include "ProtocolUtils.h"
#include "WindowImplementation.h"

namespace Protocol {
	class PROTOCOL_API GameWindow
	{
	public:
		GameWindow();
		void CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;

	private:
		WindowImplementation* mWindow;
	};
}
