#include <stdio.h>
#include <stdlib.h>

int waysToReachTarget(int target, int** types, int typesSize, int* typesColSize) {
    int dp[target + 1];
    int mod = 1000000007;

    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < typesSize; i++) {
        int count = types[i][0];
        int marks = types[i][1];

        for (int j = target; j >= 0; j--) {
            for (int k = 1; k <= count && j - k * marks >= 0; k++) {
                dp[j] = (dp[j] + dp[j - k * marks]) % mod;
            }
        }
    }

    return dp[target];
}