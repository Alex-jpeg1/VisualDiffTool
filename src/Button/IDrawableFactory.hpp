#include "Button.hpp"



namespace DrawableFactory
{
    class IDrawableFactory
    {
        public:
            IDrawableFactory(int, int);
            Drawable::IDrawable* CreateButton(int, int, int, int );

        private:
            bool checkBounds(int, int, int, int);
            int _maxWidth;
            int _maxHeight;
    };
}