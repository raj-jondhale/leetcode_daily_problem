int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int n = numsSize;
    int maxCount = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            cnt++;
            if (maxCount < cnt) {
                maxCount = cnt;
            }
        } else {
            cnt = 0;
        }
    }
    return maxCount;
}