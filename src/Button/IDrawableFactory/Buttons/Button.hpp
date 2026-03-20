#pragma once

#include "VBO/VBO.hpp"
#include "VAO/VAO.hpp"
#include "EBO/EBO.hpp"
#include "../../Vect2D/Vect2D.hpp"

class Colors
{
    public:
        static Colors RED(int);
        static Colors GREEN(int);
        static Colors BLUE(int);
    private:
        explicit Colors(int, int, int);  
};

namespace Drawable
{
    class IDrawable
    {
        public:
            IDrawable(const Vect2D& leftCorner,const Vect2D& widthLength);
            virtual void Draw() = 0;

            virtual ~IDrawable(){}

        protected:
            std::vector<GLfloat> CalculatePositions();
            Vect2D _leftUpperCorner, _widthLength; 
            VAO _vao;
            VBO _vbo;
            EBO _ebo;

    };
    class Button: public IDrawable
    {
        public:
            explicit Button(const Vect2D&, const Vect2D&);
            virtual void Draw() override;
            virtual ~Button(){};
        private:
    };
}