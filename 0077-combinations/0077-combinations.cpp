class Solution {
public:

    void solve(int index, vector<int>&nums, vector<int>v,vector<vector<int>>&ans, int k)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
       
        for(int i=index;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            solve(i+1,nums,v,ans,k);
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        vector<int>v;
        vector<vector<int>>ans;
        for(int i=1;i<=n; i++)
        nums.push_back(i);
        solve(0,nums,v,ans, k);
        return ans;
    }
};