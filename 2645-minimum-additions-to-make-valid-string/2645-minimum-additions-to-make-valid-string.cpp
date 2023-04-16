class Solution {
public:
    int addMinimum(string word) {
    if(word.length()==1)
        return 2;
    
    int ans=0;
    if(word[0]=='b')
    ans+=1;
    if(word[0]=='c')
    ans+=2;
    for(int i=0;i<word.length()-1;i++)
    {
        if(word[i]==word[i+1])
        {
            ans+=2;
        }
        else if(word[i]=='a' && word[i+1]=='c' || word[i]=='b' && word[i+1]=='a' || word[i]=='c' && word[i+1]=='b' )
        {
            ans+=1;
        }
        cout<<ans;
      

    }
    if(word[word.length()-1]=='a')
    ans+=2;
    else if(word[word.length()-1]=='b')
    ans+=1;
return ans;       
    }
};