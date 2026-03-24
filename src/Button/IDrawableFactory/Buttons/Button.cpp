#include "Button.hpp"
#include "ButtonColors/ColorValueWrapper/ColorValueWrapper.hpp"
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

bool Drawable::IDrawable::Inside(int x, int y)
{
    if( x >= _leftUpperCorner.GetX() && x <= _leftUpperCorner.GetX() + _widthLength.GetX())
    {
        if(y >= _leftUpperCorner.GetY() && y<= _leftUpperCorner.GetY() + _widthLength.GetY())
        {
            return true;
        }
    }
    return false;
}

Drawable::Button::Button(const Vect2D& leftCorner, const Vect2D& rightCorner)
    :IDrawable(leftCorner, rightCorner)
         {
            this->_vao.LinkVBO(this->_vbo, 0);
            this->_vao.LinkEBO(_ebo);
         }
void Drawable::Button::Draw(Shaders::ShadersUtils& shader)
{
    _vao.Bind();
    shader.UploadColorVector("u_Color", _color.getColor());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    _vao.Unbind();
}
void Drawable::Button::OnHover(int x, int y)
{
    if(Inside(x, y))
    {
        _color.ChangeColor(ColorValueWrapper(0), ColorValueWrapper(1), ColorValueWrapper(0), ColorValueWrapper(1));
    }
    else 
    {
        _color.ChangeColor(ColorValueWrapper(1), ColorValueWrapper(0), ColorValueWrapper(0), ColorValueWrapper(1));   
    }
}
