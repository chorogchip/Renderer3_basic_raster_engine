#include "VertexArrayBasic.h"

#include "OpenGLIncludes.h"

namespace pop::rob {

    VertexArrayBasic::VertexArrayBasic(void* vertex_data, int vertex_data_size, void* index_data, int index_data_size):
        vertex_array_(0),
        VBO_(0),
        EBO_(0),
        index_buffer_enabled_(index_data_size != 0),
        stride_(0)
    {
        glGenVertexArrays(1, &vertex_array_);

        glBindVertexArray(vertex_array_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, vertex_data_size, vertex_data, GL_STATIC_DRAW);

        if (index_buffer_enabled_) {
            glGenBuffers(1, &EBO_);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_data_size, index_data, GL_STATIC_DRAW);
        }

    }

    VertexArrayBasic::~VertexArrayBasic()
    {
        glDeleteVertexArrays(1, &vertex_array_);
        glDeleteBuffers(1, &VBO_);
        if (index_buffer_enabled_)
            glDeleteBuffers(1, &EBO_);
    }

    VertexArrayBasic& VertexArrayBasic::SetStride(int stride)
    {
        this->stride_ = stride;

        return *this;
    }

    VertexArrayBasic& VertexArrayBasic::MakeVertexAttrib(int location, int size, int type, bool is_normalized, size_t offset)
    {
        assert(stride_ > 0);
        glVertexAttribPointer(location, size, type, is_normalized, stride_, (void*)offset);
        glEnableVertexAttribArray(location);

        return *this;
    }

    void VertexArrayBasic::Bind() const
    {
        glBindVertexArray(vertex_array_);
    }
}