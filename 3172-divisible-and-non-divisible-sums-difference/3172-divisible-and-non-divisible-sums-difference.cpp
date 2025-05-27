class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum=(n*(n+1))/2; // num1+num2

        int num2=0;
        for(int i=1;i<=n;i++){
            if(i%m==0) num2+=i;
        }

        return totalSum-(2*num2); // num1+num2-2*num2= num1-num2;
    }
};