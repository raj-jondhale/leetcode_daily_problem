// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countWays(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ways = 0;

    // Case 1: select 0 students
    if (nums[0] > 0)
        ways++;

    // Check possible group sizes
    for (int k = 1; k < numsSize; k++) {
        if (nums[k - 1] < k && nums[k] > k)
            ways++;
    }

    // Case 2: select all students
    if (nums[numsSize - 1] < numsSize)
        ways++;

    return ways;
}