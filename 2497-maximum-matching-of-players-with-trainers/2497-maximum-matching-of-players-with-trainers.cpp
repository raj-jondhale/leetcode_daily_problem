class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        //we have to sort players and trainers
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));

        //calculate size
        int m=players.size();
        int n=trainers.size();

        int i=0,j=0;
        int count=0;
        while(i<m && j<n){
            if(players[i]<=trainers[j]){
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};