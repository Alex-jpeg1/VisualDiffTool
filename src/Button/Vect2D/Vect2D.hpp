#pragma once

class Vect2D final
{
    public:
        Vect2D();
        Vect2D(int, int);

        [[ nodiscard ]] int GetX() const noexcept { return _x; }
        [[ nodiscard ]] int GetY() const noexcept { return _y; }

        void ModifyLinear(int) noexcept;
        void ModifyX(int) noexcept;
        void ModifyY(int) noexcept;


    private:
        int _x;
        int _y;

};