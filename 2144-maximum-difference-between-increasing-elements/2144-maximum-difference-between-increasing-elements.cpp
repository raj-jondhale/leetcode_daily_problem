class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max=0;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    if(nums[j]-nums[i]>max){
                        max=nums[j]-nums[i];
                    }
                }
            }
        }
        return (max>0)?max:-1;
    }
};