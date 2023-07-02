class Solution {
public:
    
    bool isSubsequence(string s, string t)
    {
        int m=s.length();
        int n=t.length();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        return i==m;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        
        int low=1,high=removable.size();
        int ans=0;
        while(low<=high)
        {
            int mid=(high-low)/2 + low;
            string newString=s;
            for(int i=0;i<mid;i++)
            {
                newString[removable[i]]=' ';
            }
            
            string str="";
            for(auto x:newString)
            {
                if(x!=' ')
                {
                    str+=x;
                }
            }
            cout<<str<<endl;
            if(isSubsequence(p,str)==true)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
                high=mid-1;
            
            
            
        }
        return ans;
    }
};