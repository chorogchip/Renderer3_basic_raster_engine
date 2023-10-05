#pragma once

namespace pop::rob {

    class ShaderBasic
    {

    public:
        ShaderBasic(const char* name, const char* vertex_shader_string, const char* fragment_shader_string);
        ~ShaderBasic();
        unsigned int GetId() const { return shader_program_; }
        void Use() const;

        void SetFloat(const char* uniform_name, float value) const;

    private:
        unsigned int shader_program_;

    };

}
