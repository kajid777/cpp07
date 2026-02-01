#include <cstddef>
#include <iostream>
#include <string>

#include "Array.hpp"

// Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

template <typename T>
void printArray(Array<T> const &arr, std::string const &label) {
    std::cout << label << " (size=" << arr.size() << "): ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ' ';
    }
    std::cout << "\n";
}

int main() {
    // --- Test 1: デフォルトコンストラクタ ---
    std::cout << CYAN << "=== Test 1: Default Constructor ===" << RESET << "\n";
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << "\n\n";

    // --- Test 2: パラメータ付きコンストラクタ ---
    std::cout << CYAN << "=== Test 2: Parameterized Constructor ===" << RESET << "\n";
    Array<int> numbers(5);
    for (std::size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i * 10);
    printArray(numbers, "numbers");
    std::cout << "\n";

    // --- Test 3: コピーコンストラクタ（深いコピー） ---
    std::cout << CYAN << "=== Test 3: Copy Constructor ===" << RESET << "\n";
    Array<int> copied(numbers);
    std::cout << YELLOW << "Before: " << RESET;
    printArray(numbers, "numbers");
    numbers[0] = 99;
    std::cout << GREEN << "After numbers[0] = 99:" << RESET << "\n";
    printArray(numbers, "  numbers");
    printArray(copied, "  copied ");
    std::cout << "\n";

    // --- Test 4: std::string型 ---
    std::cout << CYAN << "=== Test 4: Array<std::string> ===" << RESET << "\n";
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "Array";
    words[2] = "Template";
    printArray(words, "words");
    std::cout << "\n";

    // --- Test 5: 代入演算子（深いコピー） ---
    std::cout << CYAN << "=== Test 5: Assignment Operator ===" << RESET << "\n";
    Array<std::string> assigned;
    assigned = words;
    std::cout << YELLOW << "Before: " << RESET;
    printArray(words, "words");
    assigned[1] = "World";
    std::cout << GREEN << "After assigned[1] = \"World\":" << RESET << "\n";
    printArray(assigned, "  assigned");
    printArray(words, "  words   ");
    std::cout << "\n";

    // --- Test 6: const配列 ---
    std::cout << CYAN << "=== Test 6: Const Array ===" << RESET << "\n";
    Array<int> const constArr(numbers);
    printArray(constArr, "constArr");
    std::cout << "\n";

    // --- Test 7: 範囲外アクセス ---
    std::cout << CYAN << "=== Test 7: Out-of-Bounds ===" << RESET << "\n";
    try {
        std::cout << "Accessing numbers[10]...\n";
        std::cout << numbers[10] << "\n";
    } catch (std::exception const &e) {
        std::cout << RED << "Exception: " << RESET << e.what() << "\n";
    }

    return 0;
}
