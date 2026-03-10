#pragma once

#include "../../../extern/glad/glad.h"
#include "../../Button/VBO/VBO.hpp"

class VAO
{
    public:
        VAO();
        ~VAO();

        void LinkVBO(VBO&, const GLuint&);
        void Bind();
        void Unbind();
        void Delete();
        
    private:
        GLuint _ID;
};
