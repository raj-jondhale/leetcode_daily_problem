// Function to compute gcd using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Main function to check if array is "good"
bool isGoodArray(int* nums, int numsSize) {
    int g = nums[0];
    for (int i = 1; i < numsSize; i++) {
        g = gcd(g, nums[i]);
        if (g == 1) return true;  // early stop optimization
    }
    return g == 1;
}
