#pragma once

#include "../../../extern/glad/glad.h"
#include "../VBO/VBO.hpp"
#include "../EBO/EBO.hpp"
class VAO
{
    public:
        VAO();
        ~VAO();

        void LinkVBO(VBO&, const GLuint&);
        void LinkEBO(EBO&);
        void Bind();
        void Unbind();
        void Delete();
        
    private:
        GLuint _ID;
};
