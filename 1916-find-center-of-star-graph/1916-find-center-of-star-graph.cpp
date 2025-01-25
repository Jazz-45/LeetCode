class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Brute Forces
        // int n=edges.size();
        // vector<int> nodeFreq(n+1);
        // for(int i=0;i<n;i++){
        //     nodeFreq[edges[i][0]-1]++;
        //     nodeFreq[edges[i][1]-1]++;
        // }
        // int center=INT_MIN;
        // int idx=-1;
        // for(int i=0;i<nodeFreq.size();i++){
        //     if(nodeFreq[i]>center){
        //         center=nodeFreq[i];
        //         idx=i;
        //     }
        // }
        // return idx+1;

        // Pick and two edge
        int a=edges[0][0];
        int b=edges[0][1];
        int c=edges[1][0];
        int d=edges[1][1];

        if(a==c || a==d) return a;
        else return b;

    }
};