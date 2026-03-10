#pragma once

#include "../../../extern/glad/glad.h"
#include <vector>

class EBO
{
    public:
        EBO(std::vector<GLfloat>);
        ~EBO();

        [[ nodiscard ]] GLuint GetID() { return _ID; }

        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint _ID;
};