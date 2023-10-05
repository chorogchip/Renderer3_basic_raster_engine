#include "OpenGLMain.h"

#include "OpenGLIncludes.h"
#include "Includes.h"

#include "ShaderBasic.h"
#include "TextureBasic.h"
#include "VertexArrayBasic.h"

#include <iostream>

void ProcessInput(GLFWwindow* window);
void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
//void DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
//    const GLchar* message, const void* userParam);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

static GLFWwindow* window_;

static pop::rob::ShaderBasic* shaders_;
static pop::rob::VertexArrayBasic* vertex_array_;
static pop::rob::TextureBasic* texture_;




const char* vertexShaderSource = R"(
#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    TexCoord = aTexCoord;
}
)";

const char* fragmentShaderSource = R"(
#version 460 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, TexCoord);
}
)";


namespace pop::ogl {
    bool Init() {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

        window_ = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
        if (window_ == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window_);
        glfwSetFramebufferSizeCallback(window_, FrameBufferSizeCallback);

        // glEnable(GL_DEBUG_OUTPUT);
        // glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        // glDebugMessageCallback(DebugMessageCallback, NULL);
        // glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        shaders_ = new pop::rob::ShaderBasic("asdf", vertexShaderSource, fragmentShaderSource);

        float vertices[] = {
                0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
                0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,
        };
        unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3,
        };

        vertex_array_ = new pop::rob::VertexArrayBasic(
            vertices, sizeof(vertices),
            indices, sizeof(indices));

        vertex_array_->Bind();
        vertex_array_->SetStride(5 * sizeof(float))
            .MakeVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, 0)
            .MakeVertexAttrib(1, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

        static char arr[16][16][3];
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j)
                arr[i][j][0] = i * 16,
                arr[i][j][1] = j * 16,
                arr[i][j][2] = rand() % 255;
        texture_ = new pop::rob::TextureBasic("asdf", arr, 16, 16);

        shaders_->Use();
        glUniform1i(glGetUniformLocation(shaders_->GetId(), "texture1"), 0);


    }

    void Update() {
        ProcessInput(window_);

        glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture_->Bind(0);
        shaders_->Use();
        vertex_array_->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }

    void Clear() {
        delete shaders_;
        delete texture_;
        delete vertex_array_;
        glfwTerminate();
    }

    bool ToClose() {
        return glfwWindowShouldClose(window_);
    }
}




void ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
/*
void DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
    const GLchar* message, const void* userParam)
{
    // Print, log, whatever based on the enums and message
}*/
