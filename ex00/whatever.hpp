#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &lhs, T &rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <typename T>
T const &min(T const &lhs, T const &rhs) {
    if (rhs <= lhs) {
        return rhs;
    }
    return lhs;
}

template <typename T>
T const &max(T const &lhs, T const &rhs) {
    if (rhs >= lhs) {
        return rhs;
    }
    return lhs;
}

#endif  // WHATEVER_HPP

