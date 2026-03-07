#pragma once
#include "../../extern/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <string>

using WindowHeight = int;
using WindowWidth = int;
using EmptyReturn = void;

namespace WindowManager
{
    class WindowUtils final
    {
        public:
            WindowUtils(WindowHeight, WindowWidth, const std::string&, GLFWmonitor* = NULL, GLFWwindow* = NULL);
            ~WindowUtils();


        private:
            EmptyReturn SetUPWindow();
            EmptyReturn SetUPHints(); // default hints
            WindowHeight _windowHeight;
            WindowWidth _windowWidth;
            std::string _windowName;
            GLFWwindow* _window;
    };
}