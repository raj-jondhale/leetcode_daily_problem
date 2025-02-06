#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int start = 0, count = 0;
    char** final_arr = (char**) malloc(numsSize * sizeof(char*));

    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i] - 1 > nums[i - 1]) {
            start = nums[i];
        }

        if (i == numsSize - 1 || nums[i] + 1 < nums[i + 1]) {
            final_arr[count] = (char*) malloc(30 * sizeof(char));  // Increased buffer size
            if (start < nums[i]) {
                snprintf(final_arr[count], 30, "%d->%d", start, nums[i]);  // Fixed formatting
            } else {
                snprintf(final_arr[count], 30, "%d", start);
            }
            count++;
        }
    }

    *returnSize = count;
    return final_arr;
}
