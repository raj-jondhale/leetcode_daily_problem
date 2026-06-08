class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>equal;
        vector<int>greater;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i]==pivot){
                equal.push_back(nums[i]);

            }else{
                greater.push_back(nums[i]);
            }
        }

        int index=0;
        for(auto it:smaller){
            nums[index++]=it;
        }
        for(auto it:equal){
            nums[index++]=it;
        }
        for(auto it:greater){
            nums[index++]=it;
        }
        return nums;
    }
};