class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(arr[j]==2*arr[i]) return true;
                }
            }else{
                for(int j=i+1;j<n;j++){
                    if(arr[j]>2*arr[i]) break;
                    else if(arr[j]<2*arr[i]) continue;
                    else return true;
                }
            }
        }
        return false;
    }
};