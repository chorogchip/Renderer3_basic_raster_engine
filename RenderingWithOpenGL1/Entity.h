#pragma once

#include "Includes.h"
#include "Vector.h"


namespace pop::ent {

    class Entity
    {
    private:
        vec::v4f position_;
        vec::v4f rotation_;

    public:
        Entity() = default;
        virtual ~Entity() = default;

        M_INLINE vec::v4f M_VCALL GetPosition() const { return position_; }
        M_INLINE vec::v4f M_VCALL GetRotation() const { return rotation_; }

        M_INLINE void M_VCALL SetPosition(vec::v4f position) { position_ = position; }
        M_INLINE void M_VCALL SetRotation(vec::v4f rotation) { rotation_ = rotation; }

    };

}

