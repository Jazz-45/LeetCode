class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Creating the adj list;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

        for(auto x: times){
            adj[x[0]-1].push_back({x[1]-1,x[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>,greater<>> pq;
        vector<int> distance(n,INT_MAX);
        pq.push({0,k-1});
        distance[k-1]=0;

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            int currTime=p.first;

            for(auto x: adj[node]){
                if (currTime + x.second < distance[x.first]) {
                    distance[x.first] = currTime + x.second;
                    pq.push({distance[x.first], x.first});
                }
            }
        }

        for(int x: distance){
            if(x==INT_MAX) return -1;
        }

        return *max_element(distance.begin(),distance.end());

    }
};