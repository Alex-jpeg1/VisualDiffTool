#pragma once

#include "../WindowManager/WindowManager.hpp"
#include <memory>
#include "../Button/IDrawableManager.hpp"

namespace MainWindow
{
    class WindowApp final
    {
        public:
        

        void Init(WindowWidth , WindowHeight , const std::string&);
        
        
        static WindowApp& GetInstance(int width, int height)
        {
            static std::unique_ptr<WindowApp> instance;

            if(!instance)
            {
                MaxWidth = width;
                MaxHeight = height;
                instance = std::unique_ptr<WindowApp>(new WindowApp(MaxWidth, MaxHeight));
            }
            return *instance;
        }
        
        void Run();

        void PositionButtons();

        private:
        WindowApp(int, int):_componentsManager(MaxWidth, MaxHeight){}

        WindowApp(const WindowApp&) = delete;
        void operator=(const WindowApp&) = delete;
        
        static int MaxWidth;
        static int MaxHeight;

        DrawableManager _componentsManager;
        std::unique_ptr<WindowManager::WindowUtils> _window;
    };
}