#include <cstddef>
#include <iostream>
#include <string>

#include "Array.hpp"

template <typename T>
void printArray(Array<T> const &array, std::string const &label) {
    std::cout << label << " (size=" << array.size() << "): ";
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i + 1 < array.size()) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << '\n';

    Array<int> numbers(5);
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = static_cast<int>(i * 10);
    }
    printArray(numbers, "numbers");

    Array<int> copied(numbers);
    numbers[0] = 99;
    printArray(numbers, "numbers modified");
    printArray(copied, "copied");

    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "Array";
    words[2] = "Template";
    printArray(words, "words");

    Array<std::string> assigned;
    assigned = words;
    assigned[1] = "World";
    printArray(assigned, "assigned modified");
    printArray(words, "words original");

    Array<int> const constNumbers(numbers);
    printArray(constNumbers, "constNumbers");

    try {
        std::cout << "Accessing out-of-bounds...\n";
        std::cout << numbers[10] << '\n';
    } catch (std::exception const &e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}

