/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kajid777 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:00:00 by kajid777          #+#    #+#             */
/*   Updated: 2025/11/24 00:00:00 by kajid777         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
 public:
    Array() : _size(0), _data(NULL) {}

    explicit Array(unsigned int n) : _size(n), _data(NULL) {
        if (_size == 0) {
            return;
        }
        _data = new T[_size]();
    }

    Array(Array const &other) : _size(other._size), _data(NULL) {
        if (_size == 0) {
            return;
        }
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    Array &operator=(Array const &other) {
        if (this == &other) {
            return *this;
        }
        T *newData = NULL;
        if (other._size != 0) {
            newData = new T[other._size];
            for (std::size_t i = 0; i < other._size; ++i) {
                newData[i] = other._data[i];
            }
        }
        delete[] _data;
        _data = newData;
        _size = other._size;
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    T &operator[](std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of range");
        }
        return _data[index];
    }

    T const &operator[](std::size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of range");
        }
        return _data[index];
    }

    std::size_t size() const {
        return _size;
    }

 private:
    std::size_t _size;
    T *_data;
};

#endif  // ARRAY_HPP

