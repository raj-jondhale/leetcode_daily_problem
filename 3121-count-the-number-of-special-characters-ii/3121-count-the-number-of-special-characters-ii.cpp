class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int count=0;

        vector<int>lastOccSmall(26,-1);
        vector<int>firstOccCapital(26,-1);

        for(int i=0;i<n;i++){
            char ch=word[i];
            if(islower(ch)){
                lastOccSmall[ch-'a']=i;
            }else{
                if(firstOccCapital[ch-'A']==-1){
                    firstOccCapital[ch-'A']=i;
                }
            }
        }

        for(int i=0;i<26;i++){
            if(firstOccCapital[i]!=-1 && lastOccSmall[i]!=-1 && lastOccSmall[i]<firstOccCapital[i]){
                count++;
            }
        }
        return count;
    }
    
};