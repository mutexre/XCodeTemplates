#include <memory>
#include <stdio.h>
#include <stdlib.h>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

static void errorCallback(int error, const char* description) {
    fputs(description, stderr);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

auto glfwWindowDeleter = [](GLFWwindow* window) {
    if (window) glfwDestroyWindow(window);
};

int main()
{
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(1);
    }

    atexit(glfwTerminate);

    auto _window = glfwCreateWindow(800, 600, "", nullptr, nullptr);
    std::unique_ptr<GLFWwindow, decltype(glfwWindowDeleter)> window(_window, glfwWindowDeleter);
    if (!window) exit(1);

    glfwMakeContextCurrent(window.get());
    glfwSwapInterval(1);
    glfwSetKeyCallback(window.get(), keyCallback);
    while (!glfwWindowShouldClose(window.get()))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window.get(), &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window.get());
        glfwPollEvents();
    }

    return 0;
}
