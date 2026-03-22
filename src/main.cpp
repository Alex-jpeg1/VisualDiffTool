#include "WindowApp/WindowApp.hpp"

int MainWindow::WindowApp::MaxWidth = 0;
int MainWindow::WindowApp::MaxHeight = 0;

int main()
{
    glfwInit();
        MainWindow::WindowApp::GetInstance(800, 800).Init(800, 800, "Fereastra mea");
        MainWindow::WindowApp::GetInstance(800, 800).Run();
    glfwTerminate();

}