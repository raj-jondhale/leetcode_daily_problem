class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<ll>rowSum(m,0);
        vector<ll>colSum(n,0);

        ll total=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
                //rowSum
                rowSum[i]+=grid[i][j];
                //colSum
                colSum[j]+=grid[i][j];
            }
        }

        if(total%2!=0){
            return false;
        }
        //horizontal check
        ll upper=0;
        for(int i=0;i<m-1;i++){
            upper+=rowSum[i];
            if(upper==total-upper){
                return true;
            }
        }
        //vertical check
        ll leftSide=0;
        for(int j=0;j<n-1;j++){
            leftSide+=colSum[j];
            if(leftSide==total-leftSide){
                return true;
            }
        }
        return false;
    }
};