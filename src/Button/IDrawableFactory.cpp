#include "IDrawableFactory.hpp"
#include "Button.hpp"

DrawableFactory::IDrawableFactory::IDrawableFactory(int maxWidth, int maxHeight)
            :_maxWidth{maxWidth},
             _maxHeight{maxHeight}
{}

Drawable::IDrawable* DrawableFactory::IDrawableFactory::CreateButton(int xPositionUpperLeft, int YPositionUpperLeft, int width, int height)
{

}

bool DrawableFactory::IDrawableFactory::checkBounds(int xPositionUpperLeft, int YPositionUpperLeft, int width, int height)
{
    
}