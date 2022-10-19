#include <iostream>
#include <ostream>

#include "config.h"
#include "vector.hh"

Vector::Vector(size_t N)
{
    vector_size = N;
    for (size_t i = 0; i < vector_size; ++i)
    {
    //     data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l)
{
}

Vector::Vector(const Vector&)
{
}

Vector& Vector::operator=(const Vector&)
{
    return *this;
}

size_t Vector::size() const
{
    return vector_size;
}

std::ostream& operator<<(std::ostream& o, const Vector& v)
{
    size_t size = v.size();
    o << "{";
    for (size_t i = 0; i < size; ++i)
    {
        o << v[i] << (i == size - 1 ? "": ",");
    }
    return o << "}";
}

Vector& Vector::operator+=(const Vector& rhs)
{
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    return *this;
}
Vector& Vector::operator+=(value v)
{
    return *this;
}
Vector& Vector::operator*=(value v)
{
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    return *this;
}
Vector Vector::operator+(value v) const
{
    return *this;
}
value Vector::operator*(const Vector& rhs) const
{
    value a = 1;
    return a;
}
Vector Vector::operator*(value v) const
{
    return *this;
}

value& Vector::operator[](size_t idx)
{
    return data[idx];
}
value Vector::operator[](size_t idx) const
{
    return data[idx];
}

Vector operator+(const value& s, const Vector& v)
{
    return v;
}
Vector operator*(const value& s, const Vector& v)
{
    return v;
}