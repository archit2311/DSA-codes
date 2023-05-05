class Solution {
public:
    bool isVovel(char ch)
    {
        if(ch=='a' ||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
        else
        return false;
    }
    int maxVowels(string s, int k) {
        unordered_map<char,int>mp;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            if(isVovel(s[i])==true)
            {
                mp[s[i]]++;
            }
        }
        for(auto x:mp)
        ans+=x.second;
    

        for(int i=k;i<s.length();i++)
        {
            if(isVovel(s[i-k])==true)
                mp[s[i-k]]--;
            
            if(isVovel(s[i])==true)
                mp[s[i]]++;

            int currmax=0;
            for( auto& x: mp )
            {
                currmax+=x.second;
            }
            ans=max(ans,currmax);
        }
        return ans;
    }
};