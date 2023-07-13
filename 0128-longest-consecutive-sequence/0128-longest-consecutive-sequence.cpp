class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
        return n;

        set<int>st;
        for(auto x:nums)
        st.insert(x);

        vector<int>v;
        for(auto x:st)
        v.push_back(x);




        int ans=1;
        int fans=INT_MIN;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]+1)
            ans++;
            else{
                fans=max(ans,fans);
                ans=1;
            }
        }
        fans=max(ans,fans);

        return fans;
    }
};