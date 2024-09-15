class Solution {
public:
    map<char,int>m;
    int findTheLongestSubstring(string s)
    {
        m['a']=1;m['e']=2;m['i']=3;m['o']=4;m['u']=5;
        map<int ,int>mp;
        mp[0]=-1;
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]=='u')
            cnt=cnt^(1<<(m[s[i]]));
        
            if(mp.count(cnt))
            {
                ans=max(ans,i-mp[cnt]);
            }
            else
                mp[cnt]=i;
        }
        return ans;

    }
};