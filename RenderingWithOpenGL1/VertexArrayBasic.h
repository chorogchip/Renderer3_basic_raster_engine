#pragma once

namespace pop::rob {

    class VertexArrayBasic
    {
    private:
        unsigned int vertex_array_;
        unsigned int VBO_;
        unsigned int EBO_;
        bool index_buffer_enabled_;

        int stride_;

    public:
        VertexArrayBasic(void* vertex_data, int vertex_data_size, void* index_data, int index_data_size);
        ~VertexArrayBasic();
        VertexArrayBasic& SetStride(int stride);
        VertexArrayBasic& MakeVertexAttrib(int location, int size, int type, bool is_normalized, size_t offset);
        void Bind() const;
    };

}

