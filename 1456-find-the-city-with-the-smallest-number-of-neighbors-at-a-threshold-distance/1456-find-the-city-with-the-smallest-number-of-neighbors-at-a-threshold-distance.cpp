class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n,vector<int>(n,1e8));

        // Adj Matrix
        for (int i=0;i<n;i++) adjMat[i][i]=0; 
        for(auto edge: edges){
            adjMat[edge[0]][edge[1]]=edge[2];
            adjMat[edge[1]][edge[0]]=edge[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (adjMat[i][k] != 1e8 && adjMat[k][j] != 1e8) {
                        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                    }
                }
            }
        }

        int cityNo=-1;
        int minCount=101;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]<=distanceThreshold) count++;
            }

            if(count<=minCount){
                minCount=count;
                cityNo=i;
            }
        }
        return cityNo;
    }
};