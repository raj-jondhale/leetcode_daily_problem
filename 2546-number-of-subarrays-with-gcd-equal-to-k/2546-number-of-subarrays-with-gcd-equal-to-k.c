// Function to calculate GCD using Euclidean algorithm.
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int subarrayGCD(int* nums, int numsSize, int k) {
    int count = 0;
    
    // Outer loop: fix starting index i.
    for (int i = 0; i < numsSize; i++) {
        
        int current_gcd = 0;
        
        // Inner loop: extend subarray to index j.
        for (int j = i; j < numsSize; j++) {
            
            if (j == i) {
                current_gcd = nums[i];
            } else {
                current_gcd = gcd(current_gcd, nums[j]);
            }
            
            if (current_gcd < k) {
                break;
            }
            
            if (current_gcd == k) {
                count++;
            }
        }
    }
    
    return count;
}