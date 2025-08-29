class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();

        int idx=-1;

        int i=0;
        bool flag=false;
        while(i<m){
            if(haystack[i]!=needle[0]){
                i++;
            }
            else{ //haystack[i]==needle[0];
                if(m-i<n) i++;
                else{
                    int j=0;
                    int temp=i;
                    while(j<n && haystack[i]==needle[j]){
                        i++;
                        j++;
                    }
                    if(j==n && !flag){
                        idx=temp;
                        flag=true;
                    }
                    i=temp+1;
                }
            }
        }
        return idx;
    }
};