#pragma once

#include "../../../../../extern/glad/glad.h"
#include <vector>

class VBO
{
    public:
        VBO(std::vector<GLfloat>);
        ~VBO();
        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint _ID;
};