#pragma once

#include "IDrawableFactory/IDrawableFactory.hpp"
#include <list>
#include <memory>

class DrawableManager
{
    public:
        int AddButton(int, int, int, int, int); // xPosition, yPosition, width, height, color
        //colors are hardcoded
        void DrawEverything();
    private:
        std::list<std::shared_ptr<Drawable::IDrawable>> _components;
        DrawableFactory::IDrawableFactory _drawableFactory;
};