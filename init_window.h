#pragma once

#include <iostream>

GLFWwindow* InitWindow(int width, int height, const char* title) {
    glfwInit();
    
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (nullptr == window) {
        std::cout << "Failed to create GLFW window";
        glfwTerminate();
        return nullptr;
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = true;
    
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return nullptr;
    }
    
    return window;
}
