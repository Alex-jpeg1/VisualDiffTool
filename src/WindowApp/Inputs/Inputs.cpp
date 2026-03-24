#include "Inputs.hpp"
#include <GLFW/glfw3.h>


//public API
void MouseInputManager::Start_Callback(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);

    glfwSetCursorPosCallback(window, Static_mouse_callback);
}

void MouseInputManager::Get_Data(int& xPos, int& yPos)
{
    xPos = _xVal;
    yPos = _yVal;
}

//private API
void MouseInputManager::Static_mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    MouseInputManager* instance = static_cast<MouseInputManager *>(glfwGetWindowUserPointer(window));

    if(instance)
    {
        instance->Handle_inputs(xPos, yPos);
    }
}

void MouseInputManager::Handle_inputs(double xPos, double yPos)
{
    _xVal = xPos;
    _yVal = yPos;
}
