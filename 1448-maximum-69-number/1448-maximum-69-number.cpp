class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);

        int n=str.length();
        int res=num;
        for(int i=0;i<n;i++){
            if(str[i]=='6'){
                str[i]='9';
                if(stoi(str)>res){
                    res=stoi(str);
                    str[i]='6';
                }
            }
        }
        return res;
    }
};