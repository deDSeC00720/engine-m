#include <cmath>
#include "quaternion/quaternion.h"

namespace MathEngine {

    Quaternion::Quaternion(): a(0) {

    }

    Quaternion::Quaternion(const float a, const Vector3d &v): a(a), v(v) {

    }

    Quaternion::Quaternion(const Quaternion &q): a(q.a), v(q.v) {

    }

    Quaternion& Quaternion::operator=(const Quaternion &q) {
        a = q.a;
        v = q.v;
        return *this;
    }

    Quaternion Quaternion::operator+(const Quaternion &q) const {
        return Quaternion(a + q.a, v + q.v);
    }

    Quaternion& Quaternion::operator+=(const Quaternion &q) {
        a += q.a;
        v += q.v;
        return *this;
    }

    Quaternion Quaternion::operator-(const Quaternion &q) const {
        return Quaternion(a - q.a, v - q.v);
    }

    Quaternion& Quaternion::operator-=(const Quaternion &q) {
        a -= q.a;
        v -= q.v;
        return *this;
    }

    Quaternion Quaternion::operator*(const Quaternion &q) const {
        return Quaternion(a * q.a - v * q.v, v * q.a + q.v * a + (v ^ q.v));
    }

    Quaternion& Quaternion::operator*=(const Quaternion &q) {
        float a = this -> a * q.a - v * q.v;
        v = v * q.a + q.v * this -> a + (v ^ q.v);
        this -> a = a;
        return *this;
    }

    Quaternion Quaternion::operator*(const float k) const {
        return Quaternion(a * k, v * k);
    }

    Quaternion& Quaternion::operator*=(const float k) {
        a *= k;
        v *= k;
        return *this;
    }

    Quaternion Quaternion::operator/(const float k) const {
        return Quaternion(a / k, v / k);
    }

    Quaternion& Quaternion::operator/=(const float k) {
        a /= k;
        v /= k;
        return *this;
    }

    float Quaternion::norm() const {
        return sqrt(a * a + v * v);
    }

    void Quaternion::normalise() {
        float n = norm();
        if (n == 0) {
            return ;
        }
        a /= n;
        v /= n;
    }

    Quaternion Quaternion::conjugate() const {
        return Quaternion(a, v * -1);
    }

    Quaternion Quaternion::inverse() const {
        Quaternion conj = conjugate();
        float n = norm();
        conj /= (n * n);
        return conj;
    }
}