/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Function to find GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
} 
char** simplifiedFractions(int n, int* returnSize) {
    char** result = (char**)malloc(5000 * sizeof(char*));
    *returnSize = 0;

    for (int denom = 2; denom <= n; denom++) {
        for (int num = 1; num < denom; num++) {
            if (gcd(num, denom) == 1) { // simplified
                result[*returnSize] =
                    (char*)malloc(10 * sizeof(char)); // enough for "100/100\0"
                sprintf(result[*returnSize], "%d/%d", num, denom);
                (*returnSize)++;
            }
        }
    }

    return result;
}