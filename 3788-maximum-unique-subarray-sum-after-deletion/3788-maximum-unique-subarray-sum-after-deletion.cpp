class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int>st(101,-1);
        // unordered_set<int>st;

        int sum=0;
        int maxNeg=INT_MIN;
        for(int &num:nums){
            if(num<=0){
                maxNeg=max(maxNeg,num);
            }else if(st[num]==-1){ //for set  !st.count(num)
                sum+=num;
                // st.insert(num);
                st[num]=1;
            }
       }
       return sum==0 ? maxNeg : sum;
    }
};