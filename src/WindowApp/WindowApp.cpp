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

void MainWindow::WindowApp::Run()
{
    while(_window->WindowActive())
    {
        _window->ColorWindowGray();
    }
}