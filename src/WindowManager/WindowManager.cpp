#include "../../extern/glad/glad.h"
#include "WindowManager.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

WindowManager::WindowUtils::WindowUtils(WindowHeight windowHeight, 
                                        WindowWidth windowWidth, 
                                        const std::string& windowName,
                                        GLFWmonitor* monitor,
                                        GLFWwindow* share)
                                        :_windowHeight{windowHeight},
                                         _windowWidth{windowWidth},
                                         _windowName{windowName},
                                         _shader{}
{
    glfwInit();
    SetUPHints();

    _window = glfwCreateWindow(_windowWidth, _windowHeight, _windowName.c_str(), monitor, share);
    
    if(_window == NULL)
    {
        throw std::runtime_error("Error with creating the window");
    }

    SetUPWindow();
    
    ActivateShader();
}

EmptyReturn WindowManager::WindowUtils::SetUPHints()
{
    //default hints

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

EmptyReturn WindowManager::WindowUtils::SetUPWindow()
{
    glfwMakeContextCurrent(_window);

    int code = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    if(code == 0)
    {
        throw std::runtime_error("Error with glad load");
    }
    glViewport( 0, 0, _windowWidth, _windowHeight);
}

EmptyReturn WindowManager::WindowUtils::ColorWindowGray()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(_window);

    glfwPollEvents();
}
WindowManager::WindowUtils::~WindowUtils()
{
    if(_window)
    {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}
EmptyReturn WindowManager::WindowUtils::ActivateShader()
{
    _shader.Activate();
}