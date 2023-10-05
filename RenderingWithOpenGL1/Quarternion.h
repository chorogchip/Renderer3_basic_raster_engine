#pragma once

#include <cmath>

#include "Includes.h"
#include "Vector.h"

namespace pop::mat {

    vec::v4f M_VCALL QTMul(vec::v4f a, vec::v4f b) {
        const float(&aa)[4] = a.m128_f32;
        const float(&bb)[4] = b.m128_f32;
        return vec::V4fSet(
            aa[3] * bb[0] + aa[0] * bb[3] + aa[1] * bb[2] - aa[2] * bb[1],
            aa[3] * bb[1] + aa[1] * bb[3] + aa[2] * bb[0] - aa[0] * bb[2],
            aa[3] * bb[2] + aa[2] * bb[3] + aa[0] * bb[1] - aa[1] * bb[0],
            aa[3] * bb[3] - aa[0] * bb[0] - aa[1] * bb[1] - aa[2] * bb[2]);
    }

    vec::v4f M_VCALL QTGetRotateByAxis(vec::v4f axis_norm, float angle) {
        angle *= 0.5f;
        float sin_t = std::sinf(angle);
        float cos_t = std::cosf(angle);
        vec::v4f ret = vec::V4fMul(axis_norm, vec::V4fSet1(sin_t));
        ret.m128_f32[3] = cos_t;
        return ret;
    }

    vec::v4f M_VCALL QTApplyRotation(vec::v4f qt_pos, vec::v4f qt_rot) {
        vec::v4f neg = vec::V4fSub(vec::V4fSetZero(), qt_rot);
        neg.m128_f32[3] = qt_rot.m128_f32[3];
        return QTMul(qt_rot, QTMul(qt_pos, neg));
    }

    void M_VCALL QTToRotationMatrix(float* dest, vec::v4f qt) {
        const float(&q)[4] = qt.m128_f32;
        const float qq[3] = { 2.0f * q[0] * q[0], 2.0f * q[1] * q[1], 2.0f * q[2] * q[2] };
        const float qqq[3] = { 2.0f * q[1] * q[2], 2.0f * q[0] * q[2], 2.0f * q[0] * q[1] };
        const float qw[3] = { 2.0f * q[0] * q[3], 2.0f * q[1] * q[3], 2.0f * q[2] * q[3] };

        dest[0] = 1.0f - qq[1] - qq[2];
        dest[1] = qqq[2] - qw[2];
        dest[2] = qqq[1] + qw[1];
        dest[3] = 0.0f;

        dest[4] = qqq[2] + qw[2];
        dest[5] = 1.0f - qq[0] - qq[2];
        dest[6] = qqq[0] - qw[0];
        dest[7] = 0.0f;

        dest[8] = qqq[1] - qw[1];
        dest[9] = qqq[0] + qw[0];
        dest[10] = 1.0f - qq[0] - qq[1];
        dest[11] = 0.0f;

        dest[12] = 0.0f;
        dest[13] = 0.0f;
        dest[14] = 0.0f;
        dest[15] = 1.0f;
    }

}