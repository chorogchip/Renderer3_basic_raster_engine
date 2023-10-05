#include "EnumDirections.h"

#include "Includes.h"
#include "vector.h"
#include "Consts.h"

namespace pop::utl {

    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection6 direction, float magnitude) {
        switch (direction) {
        case EnumDirection6::FORWARD: return vec::V4fSet(0.0f, 0.0f, -magnitude, 0.0f);
        case EnumDirection6::BACKWARD: return vec::V4fSet(0.0f, 0.0f, magnitude, 0.0f);
        case EnumDirection6::LEFT: return vec::V4fSet(-magnitude, 0.0f, 0.0f, 0.0f);
        case EnumDirection6::RIGHT: return vec::V4fSet(magnitude, 0.0f, 0.0f, 0.0f);
        case EnumDirection6::UP: return vec::V4fSet(0.0f, -magnitude, 0.0f, 0.0f);
        case EnumDirection6::DOWN: return vec::V4fSet(0.0f, magnitude, 0.0f, 0.0f);
        }
    }

    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection8 direction, float magnitude) {
        switch (direction) {
        case EnumDirection8::FORWARD_RIGHT: return vec::V4fSet(magnitude *  mat::SQRT2_HALF, 0.0f, -(magnitude * mat::SQRT2_HALF), 0.0f);
        case EnumDirection8::FORWARD: return vec::V4fSet(0.0f, 0.0f, -magnitude, 0.0f);
        case EnumDirection8::FORWARD_LEFT: return vec::V4fSet(-(magnitude * mat::SQRT2_HALF), 0.0f, -(magnitude * mat::SQRT2_HALF), 0.0f);
        case EnumDirection8::LEFT: return vec::V4fSet(-magnitude, 0.0f, 0.0f, 0.0f);
        case EnumDirection8::BACKWARD_LEFT: return vec::V4fSet(-(magnitude * mat::SQRT2_HALF), 0.0f, magnitude * mat::SQRT2_HALF, 0.0f);
        case EnumDirection8::BACKWARD: return vec::V4fSet(0.0f, 0.0f, magnitude, 0.0f);
        case EnumDirection8::BACKWARD_RIGHT: return vec::V4fSet(magnitude * mat::SQRT2_HALF, 0.0f, magnitude * mat::SQRT2_HALF, 0.0f);
        case EnumDirection8::RIGHT: return vec::V4fSet(magnitude, 0.0f, 0.0f, 0.0f);
        }
    }
    
    M_INLINE vec::v4f M_VCALL ToV4f(EnumDirection4 direction, float magnitude) {
        switch (direction) {
        case EnumDirection4::FORWARD: return vec::V4fSet(0.0f, 0.0f, -magnitude, 0.0f);
        case EnumDirection4::BACKWARD: return vec::V4fSet(0.0f, 0.0f, magnitude, 0.0f);
        case EnumDirection4::LEFT: return vec::V4fSet(-magnitude, 0.0f, 0.0f, 0.0f);
        case EnumDirection4::RIGHT: return vec::V4fSet(magnitude, 0.0f, 0.0f, 0.0f);
        }
    }
}