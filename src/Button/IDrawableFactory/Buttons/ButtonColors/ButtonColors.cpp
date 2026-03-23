#include "ButtonColors.hpp"
#include "ColorValueWrapper/ColorValueWrapper.hpp"
#include <glm/ext/vector_float4.hpp>

Colors::Colors(ColorValueWrapper red, ColorValueWrapper green, ColorValueWrapper blue, ColorValueWrapper alpha)
{
   ChangeColor(red, green, blue, alpha);    
}

void Colors::ChangeColor(ColorValueWrapper red, ColorValueWrapper green, ColorValueWrapper blue, ColorValueWrapper alpha)
{
    _red = red.GetColorQuantity();
    _green = green.GetColorQuantity();
    _blue = blue.GetColorQuantity();
    _alpha = alpha.GetColorQuantity(); 
}

glm::vec4 Colors::getColor()
{
    return glm::vec4(_red, _green, _blue, _alpha);
}