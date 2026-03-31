#include "Inputs.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
//public API
void MouseInputManager::Start_Callback(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);

    glfwSetCursorPosCallback(window, Static_mouse_callback_hover);

    glfwSetMouseButtonCallback(window, Static_mouse_callback_click);
}

void MouseInputManager::Get_Data_Hover(int& xPos, int& yPos)
{
    xPos = _xValHover;
    yPos = _yValHover;
}

bool MouseInputManager::Get_Data_Click(int& xPos, int& yPos)
{
    if(_xValClick != -1 && _yValClick != 1)
    {
        xPos = _xValClick;
        yPos = _yValClick;
        
        return true;
        //a click has happened
    }
    return false;
    //no click till that moment
}

void MouseInputManager::ClickSolved()
{
    _xValClick = -1;
    _yValClick = -1;
} 

//private API
void MouseInputManager::Static_mouse_callback_hover(GLFWwindow* window, double xPos, double yPos)
{
    MouseInputManager* instance = static_cast<MouseInputManager *>(glfwGetWindowUserPointer(window));

    if(instance)
    {
        instance->Handle_inputs_hover(xPos, yPos);
    }
}


void MouseInputManager::Static_mouse_callback_click(GLFWwindow* window, int button, int action, int mods)
{
    MouseInputManager* instance = static_cast<MouseInputManager *>(glfwGetWindowUserPointer(window));
    if(action == GLFW_PRESS)
    {
        if(button == GLFW_MOUSE_BUTTON_LEFT)
        {            
            if(instance)
            {
                instance->Handle_inputs_click();
            }
        }
    }
}

void MouseInputManager::Handle_inputs_click()
{
    _xValClick = _xValHover;
    _yValClick = _yValHover;

    //std::cout<< _xValClick << " " << _yValClick;
}

void MouseInputManager::Handle_inputs_hover(double xPos, double yPos)
{
    _xValHover = xPos;
    _yValHover = yPos;
}
