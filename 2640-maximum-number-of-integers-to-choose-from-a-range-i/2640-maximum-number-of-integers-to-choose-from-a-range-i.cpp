class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(banned.begin(),banned.end());
        // vector<int> available;

        // int j=0;
        // for(int i=1;i<=n;i++){
        //     if(j==banned.size()){
        //         if(i<n) while(i<=n) available.push_back(i);
        //         break;
        //     }
        //     else if(i==banned[j]) j++;
        //     else available.push_back(i);
        // }
        // if(available.size()==0) return 0;
        // int count=0;
        // int sum=0;
        // for(int i=0;i<available.size();i++){
        //     sum+=available[i];
        //     if(sum>maxSum) break;
        //     else count++;
        // } 
        // return count;

        unordered_set<int> s;
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n) s.insert(banned[i]);
        }

        int count=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)!=s.end()) continue;
            sum+=i;
            if(sum<=maxSum){
                count++;
            }
            else break;
        }

        return count;

    }
};