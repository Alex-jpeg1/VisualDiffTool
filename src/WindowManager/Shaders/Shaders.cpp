#include "Shaders.hpp"
#include <fstream>
#include <glm/ext/vector_float4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>

//private api

std::string Shaders::ShadersUtils::GetFileContent(const std::string& fileName)
{
    std::ifstream fin(fileName.c_str(), std::ios::binary);

    if(fin)
    {
        std::string fileVal;

        fin.seekg(0, std::ios::end);

        int fileSize = fin.tellg();

        fileVal.resize(fileSize);

        fin.seekg(0);

        fin.read(&fileVal[0], fileSize);
        fin.close();

        return fileVal;
    }
    throw std::runtime_error("Error opening file " + fileName);
}
void Shaders::ShadersUtils::CreateShader(GLuint& ID, const char *  shaderCode, int shaderType)
{
    ID = glCreateShader(shaderType);

    glShaderSource(ID, 1, &shaderCode, NULL);
    glCompileShader(ID);

}

//public api


Shaders::ShadersUtils::ShadersUtils(const std::string& vertexShader, const std::string& fragmentShader)
    :_vertexShader{GetFileContent(vertexShader)},
     _fragmentShader{GetFileContent(fragmentShader)}
{
    const char * vertexCodeCStyle = _vertexShader.c_str();
    const char * fragmentCodeCStyle = _fragmentShader.c_str();

    GLuint vertexShaderID;
    CreateShader(vertexShaderID, vertexCodeCStyle, GL_VERTEX_SHADER);

    GLuint fragmentShaderID;
    CreateShader(fragmentShaderID, fragmentCodeCStyle, GL_FRAGMENT_SHADER);

    _ID = glCreateProgram();

    glAttachShader(_ID, vertexShaderID);
    glAttachShader(_ID, fragmentShaderID);

    glLinkProgram(_ID);

    glUseProgram(_ID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}
void Shaders::ShadersUtils::Delete()
{
    glDeleteProgram(_ID);
}

void Shaders::ShadersUtils::Activate()
{
    glUseProgram(_ID);
}
int Shaders::ShadersUtils::UploadMatrix(std::string MatrixName, const glm::mat4& MatrixData)
{
    int ID = glGetUniformLocation(_ID, MatrixName.c_str());

    glUniformMatrix4fv(ID, 1, GL_FALSE, glm::value_ptr(MatrixData));

    return ID;
}
int Shaders::ShadersUtils::UploadColorVector(std::string VectorName, const glm::vec4& VectorData)
{
    int ID = glGetUniformLocation(_ID, VectorName.c_str());

    glUniform4fv(ID, 1, glm::value_ptr(VectorData));

    return ID;
}
Shaders::ShadersUtils::~ShadersUtils()
{
    Delete();
}