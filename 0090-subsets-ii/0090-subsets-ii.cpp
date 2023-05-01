class Solution {
public:

    void subset(int index, vector<int>& nums,  set<vector<int>>&s, vector<int>output)
    {
        if(index>=nums.size())
        {
            s.insert(output);
            return;
        }
        //exclude
        subset(index+1,nums,s,output);

        //include
        output.push_back(nums[index]);
        subset(index+1,nums,s,output);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>output;

        subset(0,nums,s,output);

        for(auto x:s)
        {
            ans.push_back(x);
        }

        return ans;
    }
};