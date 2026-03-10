#include "EBO.hpp"

EBO::EBO(std::vector<GLfloat> indices)
{
    glGenBuffers(1, &_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLfloat), &indices[0], GL_STATIC_DRAW);
}

void EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
}

void EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
    glDeleteBuffers(1, &_ID);
}

EBO::~EBO()
{
    Delete();
}