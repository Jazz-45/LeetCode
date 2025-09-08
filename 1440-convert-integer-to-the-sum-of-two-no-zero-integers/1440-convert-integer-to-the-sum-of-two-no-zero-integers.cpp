class Solution{
public:
    bool noZero(int n){
        if(n<=9) return n!=0;
        return n%10 && noZero(n/10);
    }

    vector<int> getNoZeroIntegers(int n){
        for(int i=1;i<n;i++){
            if(noZero(i)&&noZero(n-i)) return {i,n-i};
        }
        return {0,0};
    }
};
