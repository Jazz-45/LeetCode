class Solution {
public:
    bool isPowerOfThree(int n) {
        long long int i;
        for( i=1;i<=n;i*=3){
            if(n==i) return true;
        }
        return false;
    }
};