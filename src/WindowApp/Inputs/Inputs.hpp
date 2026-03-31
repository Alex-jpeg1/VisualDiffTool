#pragma once

#include <GLFW//glfw3.h>

class MouseInputManager
{
    public:
        void Start_Callback(GLFWwindow* window);
        void Get_Data_Hover(int& xPos, int& yPos);
    private:
        void Handle_inputs_hover(double xPos, double yPos);
        static void Static_mouse_callback(GLFWwindow* window, double xPos, double yPos);
        int _xValHover;
        int _yValHover;
};