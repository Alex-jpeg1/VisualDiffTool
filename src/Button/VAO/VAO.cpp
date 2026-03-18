#include "VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &_ID);
}

void VAO::LinkVBO(VBO& vbo, const GLuint& layout)
{
    this->Bind();

    vbo.Bind();

    glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void *)(0));
    glEnableVertexAttribArray(layout);

    vbo.Unbind();
    
    this->Unbind();
}
void VAO::Bind()
{
    glBindVertexArray(_ID);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &_ID);
}

VAO::~VAO()
{
    Delete();
}