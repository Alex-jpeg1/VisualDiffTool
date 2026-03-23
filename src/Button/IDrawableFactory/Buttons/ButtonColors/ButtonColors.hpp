#pragma once
#include "ColorValueWrapper/ColorValueWrapper.hpp"
#include "../../../../WindowManager/Shaders/Shaders.hpp"
class Colors
{
    public:
        explicit Colors(ColorValueWrapper, ColorValueWrapper, ColorValueWrapper, ColorValueWrapper);
        void UploadColor(Shaders::ShadersUtils&);
        void ChangeColor(ColorValueWrapper, ColorValueWrapper, ColorValueWrapper, ColorValueWrapper);
        
    private:
        float _red = 0;
        float _green = 0;
        float _blue = 0;
        float _aplha = 0;
};