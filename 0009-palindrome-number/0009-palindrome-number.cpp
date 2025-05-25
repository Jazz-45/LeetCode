class Solution {
public:
    bool isPalindrome(int x) {
        string num=to_string(x);
        string num2=num;
        reverse(num.begin(),num.end());
        return num==num2;
    }
};