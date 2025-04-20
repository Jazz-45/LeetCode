class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        int result=0;
        for(int i=0;i<answers.size();i++){
            if(!m[answers[i]+1]){ // we are starting a new group
                result+=answers[i]+1;

                if(answers[i]==0) continue;
                m[answers[i]+1]=1;
            }
            else{
                m[answers[i]+1]++;
                int key=answers[i]+1;
                int val=m[answers[i]+1];
                if(key==val){
                    m.erase(m[answers[i]+1]);
                }
            }
        }
        return result;
    }
};