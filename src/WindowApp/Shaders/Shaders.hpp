#pragma once

#include <string>
#include "../../../extern/glad/glad.h"

namespace Shaders
{
    class ShadersUtils final
    {
        public:
            ShadersUtils(const std::string& = "ShadersInfo/default.vert", const std::string& = "ShadersInfo/default.frag");
            
            [[ nodiscard ]] GLuint GetID() { return _ID; }

            void Activate();
            void Delete();

            int UploadMatrix(std::string);

            ShadersUtils(const ShadersUtils&) = delete; //no constructor for copying
            void operator=(const ShadersUtils&) = delete; //no operator for copying
            //The purpose of this delete is to not have 2 instances of the same Shader

            ShadersUtils(ShadersUtils&&);
            ShadersUtils& operator=(ShadersUtils&&);


            ~ShadersUtils();
        private:
        
            void CreateShader(GLuint &, const char* , int );
            [[ nodiscard]] std::string GetFileContent(const std::string&);

            std::string _vertexShader;
            std::string _fragmentShader;
            GLuint _ID;
    };
}