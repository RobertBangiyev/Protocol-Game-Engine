#include "pch.h"
#include "ProtocolApp.h"
#include <GLFW/glfw3.h>

namespace Protocol {
	void ProtocolApp::Run() {
		std::cout << "Protocol is running..." << std::endl;

		GLFWwindow* window;
		glfwInit();
		window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

		while (true) {
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void ProtocolApp::OnUpdate() {

	}

	ProtocolApp::ProtocolApp() {

	}
}