int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    long double **dp = (long double **)malloc((m + 1) * sizeof(long double *));
    for (int i = 0; i <= m; i++)
        dp[i] = (long double *)calloc(n + 1, sizeof(long double));

    // Base case: empty t can be formed in one way
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int result = (int)dp[m][n];

    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);

    return result;
}