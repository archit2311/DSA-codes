class Solution {
public:

    void swap(int &a, int &b, vector<int>&nums)
    {
        int temp=a;
        a=b;
        b=temp;
    }

    void dfs(int index,vector<int>& nums,vector<vector<int>>&ans, set<vector<int>>&s)
    {
        if(index==nums.size())
        { 
            s.insert(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[i],nums[index],nums);
            dfs(index+1,nums,ans,s);
            swap(nums[i],nums[index],nums);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>s;
        vector<vector<int>>ans;
        dfs(0,nums,ans,s);

        for(auto v:s)
        {
            ans.push_back(v);
        }
        return ans;
    }
};