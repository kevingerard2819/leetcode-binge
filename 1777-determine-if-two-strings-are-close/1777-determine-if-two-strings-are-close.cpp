class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.length()!=word2.length())
        {
            return false;
        }
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto i : word1)
        {
            mp1[i]++;
        }
        for(auto i : word2)
        {
            mp2[i]++;
        }
        for(auto i = mp1.begin();i!=mp1.end();i++)
        {
            if(mp2.count(i->first)>0 && mp2[i->first]== i->second)
            {
                mp2[i->first]=-1;
                i->second=-1;
            }
            else if(mp2.count(i->first)>0 && mp2[i->first]!=i->second)
            {
                bool flag = false;
                for(auto j = mp2.begin();j!=mp2.end();j++)
                {
                    if(i->second == j->second)
                    {
                        j->second = mp2[i->first];
                        mp2[i->first] = -1;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};