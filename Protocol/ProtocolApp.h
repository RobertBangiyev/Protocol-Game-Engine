#pragma once
#include "ProtocolUtils.h"

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

	};
}

