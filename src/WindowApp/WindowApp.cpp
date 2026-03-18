#include "WindowApp.hpp"
#include <memory>
#include "../Button/Button.hpp"

void MainWindow::WindowApp::Init(WindowWidth width, WindowHeight height, const std::string& name)
{
    if(_window != nullptr)
    {
        return;
    }
    _window = std::make_unique<WindowManager::WindowUtils>(width, height, name);
}

void MainWindow::WindowApp::Run()
{
    Drawable::Button button(Vect2D(200,200), Vect2D(200,200));

    while(_window->WindowActive())
    {
        _window->ColorWindowGray();
        button.Draw();

        _window->SwapBuffer();
        glfwPollEvents();
    }
}