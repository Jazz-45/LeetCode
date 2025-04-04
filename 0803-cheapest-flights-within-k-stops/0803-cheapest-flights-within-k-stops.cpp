class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Create a graph from guven info

        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int> distance(n,INT_MAX);

        //2. Queue will work {stops{dest,price}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        distance[src]=0;

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int stops=p.first;
            int node=p.second.first;
            int price=p.second.second;


            for(auto x: adj[node]){
                if(stops<=k && price+x.second<distance[x.first]){
                    q.push({stops+1,{x.first,price+x.second}});
                    distance[x.first]=price+x.second;
                }
            }
        }
        return (distance[dst] == INT_MAX)?-1 : distance[dst];

    }
};