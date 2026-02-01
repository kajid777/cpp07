#include <cstddef>
#include <iostream>
#include <string>

#include "iter.hpp"

// Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

template <typename T>
void printElement(T const &value) {
    std::cout << value << ' ';
}

template <typename T>
void addOne(T &value) {
    ++value;
}

template <>
void addOne<std::string>(std::string &value) {
    value += "!";
}

int main() {
    // --- Test 1: int配列 ---
    std::cout << CYAN << "=== Test 1: int array ===" << RESET << "\n";
    int numbers[] = {0, 1, 2, 3, 4};
    std::size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << YELLOW << "Before addOne: " << RESET;
    int original[] = {0, 1, 2, 3, 4};
    iter(original, numbersLen, printElement<int>);
    std::cout << "\n";

    iter(numbers, numbersLen, addOne<int>);
    std::cout << GREEN << "After addOne:  " << RESET;
    iter(numbers, numbersLen, printElement<int>);
    std::cout << "\n\n";

    // --- Test 2: string配列 ---
    std::cout << CYAN << "=== Test 2: string array ===" << RESET << "\n";
    std::string words[] = {"Hello", "CPP07", "Module"};
    std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << YELLOW << "Before addOne: " << RESET;
    std::string originalWords[] = {"Hello", "CPP07", "Module"};
    iter(originalWords, wordsLen, printElement<std::string>);
    std::cout << "\n";

    iter(words, wordsLen, addOne<std::string>);
    std::cout << GREEN << "After addOne:  " << RESET;
    iter(words, wordsLen, printElement<std::string>);
    std::cout << "\n";

    return 0;
}

