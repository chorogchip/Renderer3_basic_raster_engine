#pragma once


#include "Includes.h"
#include "Vector.h"

#include"Entity.h"

namespace pop::ent {

    class EntityMovable : public Entity
    {
    private:
        vec::v4f velocity_;

    public:
        EntityMovable() = default;
        virtual ~EntityMovable() = default;

        M_INLINE vec::v4f M_VCALL GetVelocity() const { return velocity_; }

        M_INLINE void M_VCALL SetVelocity(vec::v4f velocity_) { velocity_ = velocity_; }
    };

}

