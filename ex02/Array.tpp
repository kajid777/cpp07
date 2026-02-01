#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(NULL) {
    if (_size == 0) {
        return;
    }
    _data = new T[_size]();
}

template <typename T>
Array<T>::Array(Array const &other) : _size(other._size), _data(NULL) {
    if (_size == 0) {
        return;
    }
    _data = new T[_size];
    for (std::size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
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

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T &Array<T>::operator[](std::size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Array index out of range");
    }
    return _data[index];
}

template <typename T>
T const &Array<T>::operator[](std::size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Array index out of range");
    }
    return _data[index];
}

template <typename T>
std::size_t Array<T>::size() const {
    return _size;
}

#endif  // ARRAY_TPP
