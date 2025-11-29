class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        while(sum%k!=0){
            sum-=1;
            ans+=1;
        }
        return ans;
    }
};