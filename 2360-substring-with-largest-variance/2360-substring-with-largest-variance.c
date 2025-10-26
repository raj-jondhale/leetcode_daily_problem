int max(int a, int b) {
    return a > b ? a : b;
}

int largestVariance(char* s) {
    int n = strlen(s);
    int totalCount[26] = {0};

    for (int i = 0; i < n; i++)
        totalCount[s[i] - 'a']++;

    int globalMax = 0;

    // For each pair of characters (a, b)
    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            if (a == b || totalCount[a] == 0 || totalCount[b] == 0)
                continue;

            int diff = 0;
            int hasB = 0;
            int remainingB = totalCount[b];

            for (int i = 0; i < n; i++) {
                int c = s[i] - 'a';

                if (c == a) diff++;
                if (c == b) {
                    diff--;
                    hasB = 1;
                    remainingB--;
                }

                if (hasB)
                    globalMax = max(globalMax, diff);

                // Reset if diff < 0 and we still have more b's left
                if (diff < 0 && remainingB > 0) {
                    diff = 0;
                    hasB = 0;
                }
            }
        }
    }

    return globalMax;
}
