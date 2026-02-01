#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
 private:
    std::size_t _size;
    T *_data;
 public:
    Array();
    explicit Array(unsigned int n);
    Array(Array const &other);
    Array &operator=(Array const &other);
    ~Array();

    T &operator[](std::size_t index);
    T const &operator[](std::size_t index) const;
    std::size_t size() const;
};

#include "Array.tpp"

#endif  // ARRAY_HPP

