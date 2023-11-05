#include <application.h>
#include <iostream>

// constructor
Application::Application(std::string windowTitle, int width, int height) : _applicationName{ windowTitle },
_width{ width }, _height{ height } {};

// run function
void Application::Run()
{
	// open the window
	if (!openWindow()) {
		return;
	}

	_running = true;

	// run appliaction

	while (_running) {
		if (glfwWindowShouldClose(_window)) {
			_running = false;
			break;
		}
	
		// makes the background of the main window red
		glClearColor(1.0f, 0.3f, 0.3f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	glfwTerminate();
}

bool Application::openWindow()
{
	// initialize a window with glfwInit();
	glfwInit();

	// this is so we can be compatible with older versions
	// our version is 4.6
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// above is things needed for glfw and glad
	// below - now we open a window

	_window = glfwCreateWindow(800, 600, "MaxsOpenGL", nullptr, nullptr);
	/* (size(x, y), title, (not sure what nullptrs are about yet but using them instead
	   of NULL because NUll is C content and we are using C++) */

	if (!_window) {
		std::cerr << "failed to create GLFW window!" << std::endl;
		glfwTerminate();
	}
	// !window is the same as window == nullptr
	// cerr is console error 

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height)
		{
			// this gets called whenever the window is resized
			// std::cout << "window has resized!" << std::endl;
			glViewport(0, 0, width, height);
		});

	// below - now we load all of the OpenGl functions

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

    return true;
}

