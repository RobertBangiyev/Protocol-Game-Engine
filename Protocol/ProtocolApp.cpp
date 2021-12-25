#include "pch.h"
#include "ProtocolApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glad/glad.h"

#include "stb_image.h"

namespace Protocol {
	void ProtocolApp::Run() {
		PROTOCOL_LOG("Protocol is running...");

		/*Protocol::Shader myShader;
		myShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize", mGameWindow.GetWindowWidth(), mGameWindow.GetWindowHeight());

		Protocol::Sprite fish;
		fish.LoadImage("Assets/Textures/fish.png");*/

		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) {
			Renderer::ClearFrame();

			OnUpdate();

			//Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			std::this_thread::sleep_until(mTimeOfNextFrame);

			mGameWindow.SwapBuffers();

			/*fish.Bind();
			myShader.Use();*/

			mGameWindow.PollEvents();

			mTimeOfNextFrame += mFrameDuration;
		}

		Renderer::ShutDown();
	}

	void ProtocolApp::OnUpdate() {

	}

	void ProtocolApp::OnKeyPressed(KeyPressedEvent& event)
	{
		PROTOCOL_LOG(event.GetKeyCode());
	}

	int ProtocolApp::GetGameWindowWidth() const
	{
		return mGameWindow.GetWindowWidth();
	}

	int ProtocolApp::GetGameWindowHeight() const
	{
		return mGameWindow.GetWindowHeight();
	}

	ProtocolApp::ProtocolApp() {
		mGameWindow.CreateWindow(800, 800, "Game");

		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
	}
}