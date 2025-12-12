class Solution {
public:
    int countOdds(int low, int high) {
       int ans = 0;
       if (low % 2 == 1) {
            ++ans;
            ++low;
       } 
       int n = high - low;
       ans += (n + 1) / 2;

       return ans;
    }
};