class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    pq.push({grid[0][0], 0, 0});
    vis[0][0] = 1;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        int time = t[0], r = t[1], c = t[2];
        if (r == n-1 && c == n-1) return time;

        for (auto &d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                pq.push({max(time, grid[nr][nc]), nr, nc});
            }
        }
    }
    return -1;
    }
};