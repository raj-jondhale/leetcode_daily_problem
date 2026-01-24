class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=n-1;
        int res=0;
        while(l<r){
            int sum=nums[l]+nums[r];
            res=max(res,sum);
            l++;
            r--;
        }
        return res;
    }
};