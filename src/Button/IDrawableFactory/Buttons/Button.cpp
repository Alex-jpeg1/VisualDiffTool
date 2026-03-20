#include "Button.hpp"
#include "VBO/VBO.hpp"
#include "../../Vect2D/Vect2D.hpp"

Drawable::IDrawable::IDrawable(const Vect2D& leftCorner, const Vect2D& widthLength)
        :_leftUpperCorner{leftCorner},
         _widthLength{widthLength},
        _vbo{CalculatePositions()}
{}

std::vector<GLfloat> Drawable::IDrawable::CalculatePositions()
{
    GLfloat x = _leftUpperCorner.GetX();
    GLfloat y = _leftUpperCorner.GetY();

    GLfloat w = _widthLength.GetX();
    GLfloat h = _widthLength.GetY();

    return {
        x,     y,     
        x + w, y,     
        x,     y + h, 
        x + w, y + h  
    };
}
Drawable::Button::Button(const Vect2D& leftCorner, const Vect2D& rightCorner)
    :IDrawable(leftCorner, rightCorner)
         {
            this->_vao.LinkVBO(this->_vbo, 0);
            this->_vao.LinkEBO(_ebo);
         }
void Drawable::Button::Draw()
{
    _vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    _vao.Unbind();
}