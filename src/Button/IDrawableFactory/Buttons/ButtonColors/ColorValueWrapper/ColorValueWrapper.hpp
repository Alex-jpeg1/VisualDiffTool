#pragma once

class ColorValueWrapper
{
    public:
        explicit ColorValueWrapper(float);
        float GetColorQuantity() { return _value; }
    private:
        void ClampValue();
        float _value;
};