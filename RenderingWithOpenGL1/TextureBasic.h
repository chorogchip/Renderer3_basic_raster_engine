#pragma once

namespace pop::rob {

    class TextureBasic
    {

    public:
        TextureBasic(const char* name, void* texture_data, int width, int height);
        ~TextureBasic();
        void Bind(int bind_slot_num) const;

    private:
        unsigned int texture_;
    };
}