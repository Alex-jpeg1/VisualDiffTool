#pragma once

#include "../WindowManager/WindowManager.hpp"
#include <memory>

namespace MainWindow
{
    class WindowApp final
    {
        public:
        

        void Init(WindowWidth , WindowHeight , const std::string&);
        
        
        static WindowApp& GetInstance()
        {
            static std::unique_ptr<WindowApp> instance;

            if(!instance)
            {
                instance = std::unique_ptr<WindowApp>(new WindowApp());
            }
            return *instance;
        }
        
        void Run();

        private:
        WindowApp(){}

        WindowApp(const WindowApp&) = delete;
        void operator=(const WindowApp&) = delete;
        
        std::unique_ptr<WindowManager::WindowUtils> _window;
    };
}