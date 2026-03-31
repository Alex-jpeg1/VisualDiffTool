#include "Inputs.hpp"
#include <GLFW/glfw3.h>


//public API
void MouseInputManager::Start_Callback(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);

    glfwSetCursorPosCallback(window, Static_mouse_callback);
}

void MouseInputManager::Get_Data_Hover(int& xPos, int& yPos)
{
    xPos = _xValHover;
    yPos = _yValHover;
}

//private API
void MouseInputManager::Static_mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    MouseInputManager* instance = static_cast<MouseInputManager *>(glfwGetWindowUserPointer(window));

    if(instance)
    {
        instance->Handle_inputs_hover(xPos, yPos);
    }
}

void MouseInputManager::Handle_inputs_hover(double xPos, double yPos)
{
    _xValHover = xPos;
    _yValHover = yPos;
}
