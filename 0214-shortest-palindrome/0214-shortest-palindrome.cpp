class Solution {
public:
    void findlps(vector<int>&lps,string s){
        int pre=0;
        int suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]==0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string str=s;
        string temp = s;
        reverse(temp.begin(),temp.end());
        s+='#';
        s+=temp;
        vector<int> lps(s.size(),0);
        findlps(lps,s);
        int pc = str.size() - lps.back();
        string ans = str.substr(lps.back(),pc);
        reverse(ans.begin(),ans.end());
        ans+=str;
        return ans;

    }
};