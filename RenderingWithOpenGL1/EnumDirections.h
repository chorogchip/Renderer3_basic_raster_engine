#pragma once

#include "Includes.h"
#include "Vector.h"

namespace pop::utl {

    enum class EnumDirection6 {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        UP,
        DOWN,
    };
    enum class EnumDirection8 {
        FORWARD_RIGHT,
        FORWARD,
        FORWARD_LEFT,
        LEFT,
        BACKWARD_LEFT,
        BACKWARD,
        BACKWARD_RIGHT,
        RIGHT,
    };
    enum class EnumDirection4 {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
    };
    enum class EnumDirection4XY {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
    
    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection6 direction, float magnitude);
    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection8 direction, float magnitude);
    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection4 direction, float magnitude);
}