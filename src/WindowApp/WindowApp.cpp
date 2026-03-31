#include "WindowApp.hpp"
#include "Shaders/Shaders.hpp"
#include <memory>
#include <glm/gtc/matrix_transform.hpp>

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
    _mouseInputManager.Start_Callback(*_window);
    _componentsManager.AddButton(200, 200, 200, 200, 0);
    _componentsManager.AddButton(400, 400, 200, 200, 0);
    
    _shader = Shaders::ShadersUtils(1);

    _shader.Activate();
    glm::mat4 _projectionMatrix = glm::ortho(0.0f, static_cast<float>(MaxWidth), static_cast<float>(MaxHeight), 0.0f, -1.0f, 1.0f);

    _shader.UploadMatrix("Projection", _projectionMatrix);
}

void MainWindow::WindowApp::Run()
{
    while(_window->WindowActive())
    {
        _mouseInputManager.Get_Data_Hover(_xPosHover, _yPosHover);

        
        _window->ColorWindowGray();
        
        _componentsManager.CheckHover(_xPosHover, _yPosHover);


        bool mouseClick = _mouseInputManager.Get_Data_Click(_xPosClick, _yPosClick);

        if(mouseClick)
        {
            _componentsManager.CheckClick(_xPosClick, _yPosClick);
            _mouseInputManager.ClickSolved();
        }
        _componentsManager.DrawEverything(_shader);

        _window->SwapBuffer();
        glfwPollEvents();
    }
}