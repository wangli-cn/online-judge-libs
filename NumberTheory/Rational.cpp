typedef long long Integer;
Integer gcd(Integer a, Integer b) { return a > 0 ? gcd(b % a, a) : b; }
struct rational {
    Integer p, q;
    void normalize() { // keep q positive
        if (q < 0) p *= -1, q *= -1;
        Integer d = gcd(p < 0 ? -p : p, q);
        if (d == 0) p = 0,  q = 1;
        else        p /= d, q /= d;
    }
    rational(Integer p, Integer q = 1) : p(p), q(q) {
        normalize();
    }
    rational &operator += (const rational &a) {
        p = a.q * p + a.p * q; q = a.q * q; normalize();
        return *this;
    }
    rational &operator -= (const rational &a) {
        p = a.q * p - a.p * q; q = a.q * q; normalize();
        return *this;
    }
    rational &operator *= (const rational &a) {
        p *= a.p; q *= a.q; normalize();
        return *this;
    }
    rational &operator /= (const rational &a) {
        p *= a.q; q *= a.p; normalize();
        return *this;
    }
    rational &operator - () {
        p *= -1;
        return *this;
    }
};
rational operator + (const rational &a, const rational &b) {
    return rational(a) += b;
}
rational operator * (const rational &a, const rational &b) {
    return rational(a) *= b;
}
rational operator - (const rational &a, const rational &b) {
    return rational(a) -= b;
}
rational operator / (const rational &a, const rational &b) {
    return rational(a) /= b;
}
bool operator < (const rational &a, const rational &b) { // avoid overflow
    return (long double) a.p * b.q < (long double) a.q * b.p;
}
bool operator <= (const rational &a, const rational &b) {
    return !(b < a);
}
bool operator > (const rational &a, const rational &b) {
    return b < a;
}
bool operator >= (const rational &a, const rational &b) {
    return !(a < b);
}
bool operator == (const rational &a, const rational &b) {
    return !(a < b) && !(b < a);
}
bool operator != (const rational &a, const rational &b) {
    return (a < b) || (b < a);
}

