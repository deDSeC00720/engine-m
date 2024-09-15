#pragma once

#include "vector/vector3d.h"

namespace MathEngine {
    
    class Quaternion {
    public:
        float a;
        Vector3d v;

        Quaternion();
        Quaternion(const float, const Vector3d &);
        Quaternion(const Quaternion &);

        Quaternion& operator=(const Quaternion &);

        Quaternion operator+(const Quaternion &) const;
        Quaternion& operator+=(const Quaternion &);

        Quaternion operator-(const Quaternion &) const;
        Quaternion& operator-=(const Quaternion &);

        Quaternion operator*(const Quaternion &) const;
        Quaternion& operator*=(const Quaternion &);

        Quaternion operator*(const float) const;
        Quaternion& operator*=(const float);

        Quaternion operator/(const float) const;
        Quaternion& operator/=(const float);

        bool operator==(const Quaternion &) const;
        bool operator!=(const Quaternion &) const;

        float norm() const;
        void normalise();

        Quaternion conjugate() const;
        Quaternion inverse() const;

        ~Quaternion() = default;
    };
}
