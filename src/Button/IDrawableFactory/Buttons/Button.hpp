#pragma once

#include "VBO/VBO.hpp"
#include "VAO/VAO.hpp"
#include "EBO/EBO.hpp"
#include "../../Vect2D/Vect2D.hpp"
#include "/home/alex/Documents/VisualDiffTool/src/WindowApp/Shaders/Shaders.hpp"
#include "ButtonColors/ButtonColors.hpp"

namespace Drawable
{
    class IDrawable
    {
        public:
            IDrawable(const Vect2D& leftCorner,const Vect2D& widthLength);
            virtual void Draw(Shaders::ShadersUtils&) = 0;
            virtual void OnHover(int x, int y) = 0;

            virtual ~IDrawable(){}
            
        protected:
            bool Inside(int x, int y);
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
            virtual void Draw(Shaders::ShadersUtils&) override;
            virtual void OnHover(int, int) override;
            virtual ~Button(){};
        private:
            Colors _color;
    };
}