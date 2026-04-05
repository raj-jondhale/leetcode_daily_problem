class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.length();
        int up=0,left=0,right=0,down=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U') up++;
            if(moves[i]=='D') down++;
            if(moves[i]=='L') left++;
            if(moves[i]=='R') right++;
        }
        if(left==right && up==down){
            return true;
        }
        return false;
    }
};