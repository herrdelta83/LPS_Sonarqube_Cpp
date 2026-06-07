#ifndef PALINDROME_H
#define PALINDROME_H
#include <string>
#include <iostream>

class LPS {
    public:
        std::size_t length(std::string s);
        void findLps(std::size_t size, std::string str);
};

#endif