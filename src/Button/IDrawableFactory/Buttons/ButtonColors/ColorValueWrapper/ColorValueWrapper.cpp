#include "ColorValueWrapper.hpp"
#include <algorithm>

ColorValueWrapper::ColorValueWrapper(float value)
    :_value{value}
    {
        ClampValue();
    }

void ColorValueWrapper::ClampValue()
{
    _value = std::clamp<float>(_value, 0.0f, 1.0f);
}
