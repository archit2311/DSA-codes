class Solution {
public:

    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>v;
            for(int j=i;j<n;j++)
            {
                v.push_back(nums[j]);
                
                if(st.find(v)==st.end())
                {
                    st.insert(v);
                    int count=0;
                    for(auto x:v)
                    {
                        
                        if(x%p==0)
                        count++;
                    }
                    
                    if(count<=k)
                    ans++;
                }

            }
        }

        return ans;
    }
};