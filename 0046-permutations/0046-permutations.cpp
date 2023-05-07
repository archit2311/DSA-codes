class Solution {
public:

    void dfs(vector<int>& nums, int freq[], vector<vector<int>>&ans, vector<int>&v)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            
        }

        for(int i=0;i<nums.size();i++)
        {
            if(freq[i]==0)
            {
                v.push_back(nums[i]);
                freq[i]=1;
                dfs(nums,freq,ans,v);
                freq[i]=0;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int freq[nums.size()];
        vector<int>v;

        for(int i=0;i<nums.size();i++)
        {
            freq[i]=0;
            
        }
        dfs(nums,freq,ans,v);
        return ans;
    }
};