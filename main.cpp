#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "get_path.h"
#include "init_window.h"
#include "game.h"
#include "resource_manager.h"

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main() {
    GLFWwindow* window = InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Breakout");
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    Breakout.Init();
    
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    
    Breakout.State = GAME_MENU;
    
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();
        
        Breakout.ProcessInput(deltaTime);
        
        Breakout.Update(deltaTime);
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        Breakout.Render();
        
        glfwSwapBuffers(window);
    }
    
    ResourceManager::Clear();
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS)
            Breakout.Keys[key] = true;
        else if (action == GLFW_RELEASE)
            Breakout.Keys[key] = false;
    }
}
