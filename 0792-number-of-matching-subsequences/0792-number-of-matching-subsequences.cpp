class Solution {
public:

    bool isSubsequence(string s, string x, int n, int m)
    {
        int j=0;
        for(int i=0;i<n && j<m;i++)
        {
            if(s[i]==x[j])
            j++;
        }
        return j==m;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.length();
        map<string,bool>mp;
        int count=0;
        for(auto x:words)
        {
            if(mp.find(x)!=mp.end())
            {
                if(mp[x]==true)
                count++;
                
                continue;
            }
            mp[x]=isSubsequence(s,x,n,x.length());
            
               if(mp[x]==true)
               count++;
            
        }
        return count;
    }
};