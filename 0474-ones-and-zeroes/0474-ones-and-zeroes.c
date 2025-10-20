void countZerosOnes(char *str, int *zeros, int *ones) {
    *zeros = 0;
    *ones = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') (*zeros)++;
        else if (str[i] == '1') (*ones)++;
    }
}

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int idx = 0; idx < strsSize; idx++) {
        int zeros, ones;
        countZerosOnes(strs[idx], &zeros, &ones);
        
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                if (dp[i - zeros][j - ones] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - zeros][j - ones] + 1;
                }
            }
        }
    }

    return dp[m][n];
}