class Solution {
public:
    bool isEven(int num){
        int count;
        while(num!=0){
            count++;
            num/=10;
        }
        if(count%2==0){
            return true;
        }else{
            return false;
        }
    }

    int findNumbers(vector<int>& nums)
    {
        int ans=0;
    for(int i=0;i<nums.size();i++){
        if(isEven(nums[i])){
            ans++;
        }
    }
    return ans;
    }
};