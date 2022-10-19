// vector-test.cc
#include <iostream>
#include <ostream>

#include "config.h"
#include "vector.hh"

Vector::Vector()
{
    vector_size = NDIM;
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] = 0;
    }
}


Vector::Vector(std::initializer_list<value> l)
{
    vector_size = l.size();
    std::initializer_list<value>::iterator it;
    size_t i = 0;
    for ( it=l.begin(); it!=l.end(); ++it)
    {
        data[i++] = *it;
    }
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


size_t Vector::size() const
{
    return vector_size;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] += rhs[i];   
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] -= rhs[i];   
    }

    return *this;
}
Vector& Vector::operator+=(value v)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] += v;
    }
    return *this;
}
Vector& Vector::operator*=(value v)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    
    auto v = Vector{};
    for (size_t i = 0; i < vector_size; ++i)
    {
        v[i] = data[i] + rhs[i];
    }
    return v;
}
Vector Vector::operator+(value v) const
{
    auto vec = Vector{};
    for (size_t i = 0; i < vector_size; ++i)
    {
        vec[i] = data[i] + v;
    }
    return vec;
}

value Vector::operator*(const Vector& rhs) const
{
    value product = 0;
    for (size_t i = 0; i < vector_size; ++i)
    {
        product += data[i] * rhs[i];   
    }
    return product;
}

Vector Vector::operator*(value v) const
{
    auto vec = Vector{};
    for (size_t i = 0; i < vector_size; ++i)
    {
        vec[i] = data[i] * v;   
    }

    return vec;
}

value& Vector::operator[](size_t idx)
{
    return data[idx];
}
value Vector::operator[](size_t idx) const
{
    return data[idx];
}

Vector operator*(const value& s, const Vector& v)
{
    auto vec = Vector{};
    for (size_t i = 0; i < v.size(); ++i)
    {
        vec[i] = v[i] * s;   
    }
    return vec;
}

Vector operator+(const value& s, const Vector& v)
{
    auto vec = Vector{};
    for (size_t i = 0; i < v.size(); ++i)
    {
        vec[i] = v[i] + s;   
    }
    return vec;
}