
#define min(a,b) ((a) < (b) ? (a) : (b))

int balancedString(char* s) {
    int n = strlen(s);
    int target = n / 4;
    int count[128] = {0};

    // Count frequency of each character
    for (int i = 0; i < n; i++)
        count[(int)s[i]]++;

    // If already balanced
    if (count['Q'] == target && count['W'] == target && count['E'] == target && count['R'] == target)
        return 0;

    int res = INT_MAX;
    int left = 0;

    for (int right = 0; right < n; right++) {
        count[(int)s[right]]--;

        // While the rest of the string is balanced
        while (left < n && 
              count['Q'] <= target && 
              count['W'] <= target && 
              count['E'] <= target && 
              count['R'] <= target) {

            res = min(res, right - left + 1);
            count[(int)s[left]]++;
            left++;
        }
    }

    return res;
}