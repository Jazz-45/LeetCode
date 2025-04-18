class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        string ztr="";
        // str= 3322251
        int frq=1;
        char ch=str[0];
        for(int i=1;i<str.length();i++){
            char dh=str[i];
            if(ch==dh) frq++;
            else{
                ztr+=(to_string(frq)+ch);
                frq=1;
                ch=dh;
            }
        }
        ztr+=(to_string(frq)+ch);
        return ztr;
    }
};