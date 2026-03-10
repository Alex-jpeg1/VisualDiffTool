#include "Vect2D.hpp"

Vect2D::Vect2D(): Vect2D( 0, 0){}

Vect2D::Vect2D(int x, int y)
    :_x{x},
     _y{y}    
{}

void Vect2D::ModifyLinear(int val) noexcept
{
    ModifyX(val);
    ModifyY(val);
}

void Vect2D::ModifyX(int val) noexcept
{
    _x += val;
}

void Vect2D::ModifyY(int val) noexcept
{
    _y += val;
}