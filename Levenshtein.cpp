//
// Created by victorljli on 2023/12/20.
//

#include "Levenshtein.h"
#include <vector>

int Levenshtein::dist(const std::string &str1, const std::string &str2) {
    int n1 = str1.length() + 1;
    int n2 = str2.length() + 1;
    std::vector<std::vector<int>> dp(n1, std::vector<int>(n2));
    int t;

    for (int i = 0; i < n1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < n2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < n1; i++) {
        for (int j = 1; j < n2; j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            t = (str1[i - 1] != str2[j - 1] ? 2 : 0);
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + t);
        }
    }

    return dp[n1 - 1][n2 - 1];
}

double Levenshtein::ratio(const std::string &str1, const std::string &str2) {
    double dist = Levenshtein::dist(str1, str2);
    double sum = str1.length() + str2.length();

    return (sum - dist)/sum;
}
