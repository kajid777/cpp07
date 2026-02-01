#include <iostream>
#include <string>

#include "whatever.hpp"

// Colors
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main() {
    // --- Test 1: int ---
    std::cout << CYAN << "=== Test 1: int ===" << RESET << "\n";
    int a = 2;
    int b = 3;
    std::cout << YELLOW << "Before swap: " << RESET << "a = " << a << ", b = " << b << "\n";
    ::swap(a, b);
    std::cout << GREEN << "After swap:  " << RESET << "a = " << a << ", b = " << b << "\n";
    std::cout << "min(a, b) = " << ::min(a, b) << "\n";
    std::cout << "max(a, b) = " << ::max(a, b) << "\n\n";

    // --- Test 2: string ---
    std::cout << CYAN << "=== Test 2: string ===" << RESET << "\n";
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << YELLOW << "Before swap: " << RESET << "c = " << c << ", d = " << d << "\n";
    ::swap(c, d);
    std::cout << GREEN << "After swap:  " << RESET << "c = " << c << ", d = " << d << "\n";
    std::cout << "min(c, d) = " << ::min(c, d) << "\n";
    std::cout << "max(c, d) = " << ::max(c, d) << "\n";

    return 0;
}

