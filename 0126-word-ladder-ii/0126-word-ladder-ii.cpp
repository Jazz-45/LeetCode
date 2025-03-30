class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,int> distance;
    string beginWord;
    
    // DFS/backtracking: starting from word, add all valid predecessors (i.e. one step closer to beginWord)
    void dfs(string word, vector<string>& path) {
        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        int steps = distance[word];
        for (int i = 0; i < word.size(); i++) {
            string prev = word;
            for (char c = 'a'; c <= 'z'; c++) {
                prev[i] = c;
                // If the word exists in the distance map and is exactly one step closer,
                // it is a valid predecessor.
                if(distance.count(prev) && distance[prev] == steps - 1) {
                    path.push_back(prev);
                    dfs(prev, path);
                    path.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->beginWord = beginWord;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // if endWord is not in the dictionary, there is no valid transformation.
        if(!dict.count(endWord)) return {};
        
        // Initialize BFS
        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 1; // starting level
        
        int minLevel = INT_MAX;
        int wordLen = beginWord.size();
        
        // BFS to find the shortest path distance for every word reachable from beginWord.
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int currLevel = distance[word];
            if(currLevel > minLevel) 
                break;  // we've processed all words of the shortest path length
            
            for(int i = 0; i < wordLen; i++){
                string nextWord = word;
                for(char c = 'a'; c <= 'z'; c++){
                    nextWord[i] = c;
                    if(!dict.count(nextWord))
                        continue;
                    
                    // If nextWord hasn't been visited, or we found it at the same level (multiple shortest paths)
                    if(!distance.count(nextWord)) {
                        distance[nextWord] = currLevel + 1;
                        if(nextWord == endWord)
                            minLevel = currLevel + 1;
                        q.push(nextWord);
                    }
                }
            }
        }
        
        // If endWord is unreachable, return empty vector.
        if(!distance.count(endWord))
            return ans;
        
        // Use DFS to backtrack from endWord to beginWord using the distance information.
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, path);
        
        return ans;
    }
};
