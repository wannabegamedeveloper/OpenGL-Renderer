#include "Window.h"

Window::Window(int WIDTH, int HEIGHT, const char* title, GLFWmonitor* monitor)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, title, monitor, NULL);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		std::cout << "Failed to initialize GLAD" << std::endl;

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

GLFWwindow* Window::GetWindowInstance()
{
	return window;
}

void Window::GetWindowSize(int* WIDTH, int* HEIGHT)
{
	glfwGetWindowSize(window, WIDTH, HEIGHT);
}

