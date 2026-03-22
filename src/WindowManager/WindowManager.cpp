#include "../../extern/glad/glad.h"
#include "Shaders/Shaders.hpp"
#include "WindowManager.hpp"
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float4.hpp>
#include <stdexcept>

constexpr int Reinitialize = 1;

WindowManager::WindowUtils::WindowUtils(WindowHeight windowHeight, 
                                        WindowWidth windowWidth, 
                                        const std::string& windowName,
                                        GLFWmonitor* monitor,
                                        GLFWwindow* share)
                                        :_windowHeight{windowHeight},
                                         _windowWidth{windowWidth},
                                         _windowName{windowName}
{

    _projectionMatrix = glm::ortho(0.0f, static_cast<float>(_windowWidth), static_cast<float>(_windowHeight), 0.0f, -1.0f, 1.0f);
    
    SetUPHints();

    _window = glfwCreateWindow(_windowWidth, _windowHeight, _windowName.c_str(), monitor, share);
    
    if(_window == NULL)
    {
        throw std::runtime_error("Error with creating the window");
    }

    SetUPWindow();

    _shader = Shaders::ShadersUtils(Reinitialize);
    ActivateShader();
    
    glm::vec4 Color(0.0, 1.0, 0.0, 1.0);
    _shader.UploadColorVector("u_Color", Color);
    _shader.UploadMatrix("Projection", _projectionMatrix);
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


}
WindowManager::WindowUtils::~WindowUtils()
{
    if(_window)
    {
        glfwDestroyWindow(_window);
    }
}
EmptyReturn WindowManager::WindowUtils::ActivateShader()
{
    _shader.Activate();
}

EmptyReturn WindowManager::WindowUtils::SwapBuffer()
{
    glfwSwapBuffers(_window);
}