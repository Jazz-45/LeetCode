class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        // Business line priority
        unordered_map<string,int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int,string>> valid; 
        // (businessLinePriority, code)

        for(int i=0;i<n;i++){
            // Condition 1: must be active
            if(!isActive[i]) continue;

            // Condition 2: valid business line
            if(priority.find(businessLine[i]) == priority.end())
                continue;

            // Condition 3: valid code
            if(code[i].empty()) continue;

            bool ok = true;
            for(char c : code[i]){
                if(!isalnum(c) && c != '_'){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;

            valid.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by business line order, then lexicographically by code
        sort(valid.begin(), valid.end(), [](auto &a, auto &b){
            if(a.first != b.first) 
                return a.first < b.first;
            return a.second < b.second;
        });

        // Extract only codes
        vector<string> result;
        for(auto &p : valid){
            result.push_back(p.second);
        }

        return result;
    }
};
