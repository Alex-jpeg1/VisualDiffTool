#pragma once

#include <glm/ext/vector_float4.hpp>
#include <string>
#include "../../../extern/glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Shaders
{
    class ShadersUtils final
    {
        public:
            ShadersUtils(){}
            ShadersUtils(int,
                        const std::string& = "/home/alex/Documents/VisualDiffTool/src/WindowApp/Shaders/ShaderInfo/default.vert", 
                        const std::string& = "/home/alex/Documents/VisualDiffTool/src/WindowApp/Shaders/ShaderInfo/default.frag");
            
            [[ nodiscard ]] GLuint GetID() { return _ID; }

            void Activate();
            void Delete();

            int UploadMatrix(std::string, const glm::mat4&);
            int UploadColorVector(std::string, const glm::vec4&);

            ~ShadersUtils();
        private:
        
            void CreateShader(GLuint &, const char* , int );
            [[ nodiscard]] std::string GetFileContent(const std::string&);

            std::string _vertexShader;
            std::string _fragmentShader;
            GLuint _ID;
    };
}