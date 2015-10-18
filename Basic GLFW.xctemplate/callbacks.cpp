#include "callbacks.h"
#include "shared.h"
#include "option.h"

void windowSizeCallback(GLFWwindow* window, int w, int h) {
    reshape(w, h);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GL_TRUE);
            break;

            default: break;
        }
    }
}

void charCallback(GLFWwindow* window, unsigned int code) {
    switch (code) {
        case 'q':
            glfwSetWindowShouldClose(window, GL_TRUE);
        break;

        default: break;
    }
}

struct {
    bool left{ false };
    bool right{ false };
}
mouse;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_1)
        mouse.left = action == GLFW_PRESS;

    if (button == GLFW_MOUSE_BUTTON_2)
        mouse.right = action == GLFW_PRESS;
}

void cursorEnterCallback(GLFWwindow* window, int entered) {
}

struct XY {
    float x, y;
};
Option<XY> lastCursorCoord;

void cursorPosCallback(GLFWwindow* window, double x, double y) {
    float dx, dy;

    if (lastCursorCoord) {
        dx = x - lastCursorCoord.value.x;
        dy = y - lastCursorCoord.value.y;
    }
    else
        dx = dy = 0.f;

    lastCursorCoord.define(XY{ float(x), float(y) });
}

void scrollCallback(GLFWwindow* window, double x, double y) {
}

void setupGlfwCallbacks(GLFWwindow* window) {
    glfwSetKeyCallback(window, keyCallback);
    glfwSetWindowSizeCallback(window, windowSizeCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCharCallback(window, charCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorEnterCallback(window, cursorEnterCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetScrollCallback(window, scrollCallback);
}
