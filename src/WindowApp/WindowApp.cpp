#include "WindowApp.hpp"
#include <memory>


void MainWindow::WindowApp::Init(WindowWidth width, WindowHeight height, const std::string& name)
{
    if(_window != nullptr)
    {
        return;
    }
    _window = std::make_unique<WindowManager::WindowUtils>(width, height, name);
}

void MainWindow::WindowApp::PositionButtons()
{
    _componentsManager.AddButton(200, 200, 200, 200, 0);
    _componentsManager.AddButton(400, 400, 200, 200, 0);
}

void MainWindow::WindowApp::Run()
{
    while(_window->WindowActive())
    {
        _window->ColorWindowGray();
        _componentsManager.DrawEverything(_shader);

        _window->SwapBuffer();
        glfwPollEvents();
    }
}