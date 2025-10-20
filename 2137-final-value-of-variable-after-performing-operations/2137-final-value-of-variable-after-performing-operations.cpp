class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;

        for(auto it: operations){
            if(it[0]=='-') x--;
            else if(it[0]=='+') x++;
            else if(it[1]=='+') x++;
            else x--;
        }

        return x;
    }
};