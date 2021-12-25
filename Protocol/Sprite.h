#pragma once

#include "pch.h"
#include "ProtocolUtils.h"
#include "SpriteImplementation.h"

namespace Protocol {
	class PROTOCOL_API Sprite
	{
	public:
		Sprite();

		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();

	private:
		std::unique_ptr<SpriteImplementation> mSpriteImplementation;
	};
}

