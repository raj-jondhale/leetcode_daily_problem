
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    // Create DP table
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++)
        dp[i] = (int*)malloc((n + 1) * sizeof(int));

    // Base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i; // Deleting all characters
    for (int j = 0; j <= n; j++)
        dp[0][j] = j; // Inserting all characters

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No change needed
            } else {
                dp[i][j] = 1 + min(
                    dp[i - 1][j],     // Delete
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j - 1]  // Replace
                );
            }
        }
    }

    int result = dp[m][n];

    // Free memory
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);

    return result;
}