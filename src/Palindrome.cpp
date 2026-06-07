#include "../include/Palindrome.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>
#include <vector>

std::size_t LPS::length(std::string s) {
    return s.size();
}

void LPS::findLps(std::size_t size, std::string str) {
    std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
    int leftNeighbor = 0;
    int downNeighbor = 0;
    int innerNeighbor = 0;
    int maxNeighbor = 0;

    for (int k = 0; k <= (int)size; k++) {
        for (int i = 0; i < (int)size - k; i++) {
            int j = i + k;
            if (k == 0) {
                dp[i][j] = 1;
            } else if (k == 1) {
                dp[i][j] = (str[i] == str[j]) ? 2 : 1;
            } else {
                if (str[i] == str[j]) {
                    leftNeighbor = dp[i][j - 1];
                    downNeighbor = dp[i + 1][j];
                    innerNeighbor = dp[i + 1][j - 1];
                    maxNeighbor = std::max(leftNeighbor, downNeighbor);

                    if (maxNeighbor > innerNeighbor) {
                        dp[i][j] = 2 + innerNeighbor;
                    } else {
                        dp[i][j] = 2 + maxNeighbor;
                    }
                } else {
                    leftNeighbor = dp[i][j - 1];
                    downNeighbor = dp[i + 1][j];
                    dp[i][j] = std::max(leftNeighbor, downNeighbor);
                }
            }
        }
    }

    std::cout << "LPS: (" << dp[0][size - 1] << ")" << '\n' << std::endl;

    int lpsLen = dp[0][size - 1];
    std::string lpsStr(lpsLen, ' ');

    int rowIdx = 0;
    int colIdx = (int)size - 1;
    int leftIdx = 0;
    int rightIdx = lpsLen - 1;

    while (rowIdx <= colIdx) {
        if (str[rowIdx] == str[colIdx]) {
            lpsStr[leftIdx] = str[rowIdx];
            lpsStr[rightIdx] = str[colIdx];
            leftIdx++;
            rightIdx--;
            rowIdx++;
            colIdx--;
        } else {
            int valLeft = (colIdx > 0) ? dp[rowIdx][colIdx - 1] : 0;
            int valDown = (rowIdx + 1 < (int)size) ? dp[rowIdx + 1][colIdx] : 0;
            if (valLeft > valDown) {
                colIdx--;
            } else {
                rowIdx++;
            }
        }
    }

    std::cout << "Longest Palindromic Subsequence: " << lpsStr << std::endl;
}
