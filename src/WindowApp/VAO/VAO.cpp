#include "VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &_ID);
}

void VAO::LinkVBO(VBO& vbo, )