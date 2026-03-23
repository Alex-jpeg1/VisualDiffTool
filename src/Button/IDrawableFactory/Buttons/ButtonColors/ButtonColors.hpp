#pragma once
#include "ColorValueWrapper/ColorValueWrapper.hpp"
#include <glm/ext/vector_float4.hpp>

class Colors
{
    public:
        explicit Colors(ColorValueWrapper = ColorValueWrapper{1}, ColorValueWrapper = ColorValueWrapper{0}, ColorValueWrapper = ColorValueWrapper{0}, ColorValueWrapper = ColorValueWrapper{1});
        glm::vec4 getColor();
        void ChangeColor(ColorValueWrapper, ColorValueWrapper, ColorValueWrapper, ColorValueWrapper);

    private:
        float _red = 0;
        float _green = 0;
        float _blue = 0;
        float _alpha = 0;
};