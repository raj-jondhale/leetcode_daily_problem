class Solution {
public:
    int numSub(string s) {
        const long MOD=1000000007;
        int cnt=0;
        int ans=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                ans=(ans+cnt) % MOD;
            }else{
                cnt=0;
            }
        }
        return ans;
    }
};