class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x: times){
            adj[x[0]-1].push_back({x[1]-1,x[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[k-1]=0;
        pq.push({0,k-1});

        while(!pq.empty()){
            auto p= pq.top();
            pq.pop();

            int node=p.second,distance=p.first;
            for(auto x: adj[node]){
                if(distance+x.second<dist[x.first]){
                    dist[x.first]=distance+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }

        for(int x: dist){
            if(x==1e9) return -1;
        }
        return *max_element(dist.begin(),dist.end());

    }
};