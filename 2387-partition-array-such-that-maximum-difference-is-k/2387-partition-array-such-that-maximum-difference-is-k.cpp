class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        int count=1;//first subsequence
        int minVal=nums[0];

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]-minVal>k){
                count++;
                minVal=nums[i];
            }
        }
        return count;
    }
};