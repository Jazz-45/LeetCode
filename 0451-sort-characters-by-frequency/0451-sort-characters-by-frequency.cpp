class Solution {
    private:
    static bool compare(pair<char,int>&a, pair<char,int>&b){
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {

        unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            freq[ch]++;
        }

        vector<pair<char,int>> vec(freq.begin(),freq.end());

        sort(vec.begin(),vec.end(), compare);

        string ans = "";
        for(int i=0;i<vec.size();i++){
            char ch = vec[i].first;
            int count = vec[i].second;

            for(int i=0;i<count;i++){
                ans+= ch;
            }
        }

        return ans;
        
    }
};