#pragma once

#include <immintrin.h>

#include "Includes.h"

namespace pop::vec {


using v4f = __m128;
using v4i = __m128i;

M_INLINE v4f M_VCALL V4fSetZero() {
    return _mm_setzero_ps();
}
M_INLINE v4f M_VCALL V4fSet(float x, float y, float z, float w) {
    return _mm_set_ps(x, y, z, w);
}
M_INLINE v4f M_VCALL V4fSet1(float val) {
    return _mm_set_ps1(val);
}

M_INLINE v4f M_VCALL V4fAdd(v4f a, v4f b) {
    return _mm_add_ps(a, b);
}
M_INLINE v4f M_VCALL V4fSub(v4f a, v4f b) {
    return _mm_sub_ps(a, b);
}
M_INLINE v4f M_VCALL V4fMul(v4f a, v4f b) {
    return _mm_mul_ps(a, b);
}


}