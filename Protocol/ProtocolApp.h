#pragma once
#include "ProtocolUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30

namespace Protocol
{
	class PROTOCOL_API ProtocolApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent& event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;

	protected:
		ProtocolApp();
	private:
		GameWindow mGameWindow;

		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
	};
}

