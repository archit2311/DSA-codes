class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n=secret.length();
        unordered_map<char,int>mp;
        int same=0,diff=0;

        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i])
            mp[secret[i]]++;
        }

      

        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            same++;
        }

        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i] && mp.find(guess[i])!=mp.end() && mp[guess[i]]>=1){
            diff++;
            mp[guess[i]]--;
            }
        }
        
        string ans="";
        ans=to_string(same)+'A'+to_string(diff)+'B';
        return ans;
    }
};