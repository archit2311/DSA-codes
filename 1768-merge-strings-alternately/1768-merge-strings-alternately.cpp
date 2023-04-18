class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        
        string ans="";
        int i=0,j=0;
        while(i<m && j<n)
        {
            ans=ans+word1[i]+word2[j];
            i++;
            j++;
        }

        if(i<m)
        {
            ans+=word1.substr(i,m-i);
        }
        if(j<n)
        {
            ans+=word2.substr(j,n-j);
        }

        return ans;
    }
};