#include "WindowApp/WindowApp.hpp"

int main()
{
    glfwInit();
        MainWindow::WindowApp::GetInstance().Init(800, 800, "Fereastra mea");
        MainWindow::WindowApp::GetInstance().Run();
    glfwTerminate();

}