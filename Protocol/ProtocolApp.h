#pragma once
#include "ProtocolUtils.h"
#include "GameWindow.h"

namespace Protocol
{
	class PROTOCOL_API ProtocolApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	protected:
		ProtocolApp();
	private:
		GameWindow mGameWindow;
	};
}

