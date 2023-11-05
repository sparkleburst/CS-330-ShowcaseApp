#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application {
public:
	Application(std::string windowTitle, int width, int height);

	void Run();
private:
	//this is a private function so will start with lowercase for readability
	bool openWindow();

private:
	//to make it clear all private variables will have an underscore
	std::string _applicationName {};
	int _width {};
	int _height {};
	GLFWwindow* _window { nullptr };

	bool _running{ false };
};