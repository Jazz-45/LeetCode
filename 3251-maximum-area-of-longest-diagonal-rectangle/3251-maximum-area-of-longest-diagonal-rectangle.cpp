class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diagonal=INT_MIN;
        int area=0;

        for(auto vec: dimensions){
            int x=vec[0],y=vec[1];
            double diag=sqrt(x*x+y*y);
            if(diag>diagonal){
                diagonal=diag;
                area=x*y;
            }
            else if(diag==diagonal){
                area=max(area,x*y);
            }
        }
        return area;
    }
};