
#include "ShaderBasic.h"

#include "OpenGLIncludes.h"

#include <iostream>

namespace pop::rob {

    ShaderBasic::ShaderBasic(const char* name, const char* vertex_shader_string, const char* fragment_shader_string):
        shader_program_(0)
    {
        int succeed;
        char info_log[512];
        
        unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertex_shader_string, NULL);
        glCompileShader(vertex);

        glGetShaderiv(vertex, GL_COMPILE_STATUS, &succeed);
        if (!succeed) {
            glGetShaderInfoLog(vertex, sizeof(info_log), NULL, info_log);
            std::cout << "vertex shader for [" << name << "] compilation failed : " << info_log << std::endl;
        }

        unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragment_shader_string, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &succeed);
        if (!succeed) {
            glGetShaderInfoLog(fragment, sizeof(info_log), NULL, info_log);
            std::cout << "fragment shader for [" << name << "] compilation failed : " << info_log << std::endl;
        }

        shader_program_ = glCreateProgram();
        glAttachShader(shader_program_, vertex);
        glAttachShader(shader_program_, fragment);
        glLinkProgram(shader_program_);

        glGetShaderiv(shader_program_, GL_LINK_STATUS, &succeed);
        if (!succeed) {
            glGetProgramInfoLog(shader_program_, sizeof(info_log), NULL, info_log);
            std::cout << "shader program for [" << name << "] linking failed : " << info_log << std::endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    ShaderBasic::~ShaderBasic() {
        glDeleteProgram(shader_program_);
    }

    void ShaderBasic::Use() const {
        glUseProgram(shader_program_);
    }


    void ShaderBasic::SetFloat(const char* uniform_name, float value) const {
        glUniform1f(glGetUniformLocation(shader_program_,  uniform_name), value);
    }


}
