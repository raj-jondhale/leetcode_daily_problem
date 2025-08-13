class Solution {
public:
    bool isPowerOfThree(int n) { 
        //3 raised to the 19th power is 1,162,261,467
        return n > 0 && 1162261467 % n == 0; 

    }
};