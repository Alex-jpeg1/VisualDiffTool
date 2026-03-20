#pragma once

#include "Buttons/Button.hpp"



namespace DrawableFactory
{
    class IDrawableFactory
    {
        public:
            IDrawableFactory(int, int);
            Drawable::IDrawable* CreateButton(int, int, int, int );

        private:
            bool CheckBounds(int, int, int, int);
            bool CheckValueBetween(int, int, int);
            int _maxWidth;
            int _maxHeight;
    };
}