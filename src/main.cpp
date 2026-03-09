#include "WindowApp/WindowApp.hpp"

int main()
{
    MainWindow::WindowApp::GetInstance().Init(800, 800, "Fereastra mea");
    MainWindow::WindowApp::GetInstance().Run();
}