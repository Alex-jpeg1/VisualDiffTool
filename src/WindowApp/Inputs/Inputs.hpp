#pragma once

#include <GLFW//glfw3.h>

class MouseInputManager
{
    public:
        void Start_Callback(GLFWwindow* window);
        void Get_Data_Hover(int& xPos, int& yPos);
        bool Get_Data_Click(int& xPos, int& yPos);

        void ClickSolved();
    private:
        void Handle_inputs_hover(double xPos, double yPos);
        void Handle_inputs_click();
        static void Static_mouse_callback_hover(GLFWwindow* window, double xPos, double yPos);
        static void Static_mouse_callback_click(GLFWwindow* window, int button, int action, int mods);
        int _xValClick;
        int _yValClick;
        int _xValHover;
        int _yValHover;
};