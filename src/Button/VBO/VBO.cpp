#include "VBO.hpp"

VBO::VBO(std::vector<GLfloat> vertices)
{
    glGenBuffers(1, &_ID);
    glBindBuffer(GL_ARRAY_BUFFER, _ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _ID);
}

void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void VBO::Delete()
{
    glDeleteBuffers(1, &_ID);
}

VBO::~VBO()
{
    Delete();
}