#include <memory>
#include <stdio.h>
#include <stdlib.h>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "callbacks.h"
#include "shared.h"

void errorCallback(int error, const char* description) {
    fputs(description, stderr);
}

void reshape(float w, float h) {
    //auto aspect = w / h;
    glViewport(0, 0, w, h);
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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int w = 800;
    int h = 600;
    auto _window = glfwCreateWindow(w, h, "", nullptr, nullptr);
    std::unique_ptr<GLFWwindow, decltype(glfwWindowDeleter)> window(_window, glfwWindowDeleter);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        exit(1);
    }

    glfwMakeContextCurrent(window.get());
    glfwSwapInterval(1);

    glfwGetFramebufferSize(window.get(), &w, &h);
    reshape(w, h);

    setupGlfwCallbacks(window.get());

    glClearColor(0.f, 1.f, 1.f, 1.f);
    while (!glfwWindowShouldClose(window.get())) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window.get());
        glfwPollEvents();
    }

    return 0;
}
