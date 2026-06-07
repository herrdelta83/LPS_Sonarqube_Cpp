#include <iostream>
#include <algorithm>
#include <vector>
#include "../include/Palindrome.h"

int main() {
    LPS lps;
    std::string inputStr;
    std::cout << "Enter a string to find its Longest Palindromic Subsequence: ";
    std::getline(std::cin, inputStr);
    std::size_t strLength = lps.length(inputStr);
    lps.findLps(strLength, inputStr);
    return 0;
}