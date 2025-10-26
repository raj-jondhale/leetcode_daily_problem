long long makePalindrome(long long left, int len) {
    char s[25];
    sprintf(s, "%lld", left);
    int n = strlen(s);
    char pal[25];
    strcpy(pal, s);

    // mirror
    for (int i = len % 2 ? n - 2 : n - 1; i >= 0; i--) {
        char c[2] = { s[i], '\0' };
        strcat(pal, c);
    }

    return atoll(pal);
}

// main logic
char* nearestPalindromic(char* n) {
    int len = strlen(n);
    long long num = atoll(n);

    long long left = atoll(strndup(n, (len + 1) / 2));

    long long candidates[5];
    int idx = 0;

    // mirror left, left+1, left-1
    candidates[idx++] = makePalindrome(left, len);
    candidates[idx++] = makePalindrome(left + 1, len);
    candidates[idx++] = makePalindrome(left - 1, len);

    // 999..9 and 100..001
    long long pow10 = 1;
    for (int i = 0; i < len - 1; i++) pow10 *= 10;
    candidates[idx++] = pow10 - 1;
    pow10 *= 10;
    candidates[idx++] = pow10 + 1;

    long long best = -1;

    for (int i = 0; i < idx; i++) {
        long long c = candidates[i];
        if (c == num) continue;
        if (c < 0) continue;

        if (best == -1 ||
            llabs(c - num) < llabs(best - num) ||
            (llabs(c - num) == llabs(best - num) && c < best)) {
            best = c;
        }
    }

    static char result[25];
    sprintf(result, "%lld", best);
    return result;
}
