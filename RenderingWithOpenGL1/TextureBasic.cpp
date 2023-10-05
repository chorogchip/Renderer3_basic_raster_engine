
#include "TextureBasic.h"

#include "OpenGLIncludes.h"

namespace pop::rob {

    TextureBasic::TextureBasic(const char* name, void* texture_data, int width, int height):
        texture_(0)
    {
        glGenTextures(1, &texture_);
        glBindTexture(GL_TEXTURE_2D, texture_);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
        glGenerateMipmap(GL_TEXTURE_2D);

    }

    TextureBasic::~TextureBasic() {
        glDeleteTextures(1, &texture_);
    }

    void TextureBasic::Bind(int bind_slot_num) const {
        glActiveTexture(GL_TEXTURE0 + bind_slot_num);
        glBindTexture(GL_TEXTURE_2D, texture_);
    }
}
