#include "IDrawableFactory.hpp"
#include <stdexcept>

DrawableFactory::IDrawableFactory::IDrawableFactory(int maxWidth, int maxHeight)
            :_maxWidth{maxWidth},
             _maxHeight{maxHeight}
{}

Drawable::IDrawable* DrawableFactory::IDrawableFactory::CreateButton(int xPositionUpperLeft, int YPositionUpperLeft, int width, int height)
{

    bool valid = CheckBounds(xPositionUpperLeft, YPositionUpperLeft, width, height);

    if(!valid)
    {
        throw std::runtime_error(static_cast<std::string>("Error with creating button.") + 
                                "Button does not allign with the window dimensions.");
    }

    return new Drawable::Button(Vect2D{xPositionUpperLeft, YPositionUpperLeft}, Vect2D{width, height});
}

bool DrawableFactory::IDrawableFactory::CheckBounds(int xPositionUpperLeft, int YPositionUpperLeft, int width, int height)
{
    bool checkWidth;
    bool checkHeight;

    checkWidth = this->CheckValueBetween(0, xPositionUpperLeft, this->_maxWidth) &&
                 this->CheckValueBetween(0, xPositionUpperLeft + width, this->_maxWidth);

    checkHeight = this->CheckValueBetween(0, YPositionUpperLeft, this->_maxHeight) &&
                  this->CheckValueBetween(0, YPositionUpperLeft + height, this->_maxHeight);
    return checkHeight & checkWidth;
}

bool DrawableFactory::IDrawableFactory::CheckValueBetween(int leftBound, int val, int rightBound)
{
    return (leftBound <= val && rightBound >= val);
}