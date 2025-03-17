class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto& p:mp){
            if(p.second %2 !=0){
                return false;
            }
        }
        return true;
    }
};