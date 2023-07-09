class Solution {
public:

    void solve(int ind, vector<int>v,vector<int>& candidates, int target,vector<vector<int>>&ans,int k)
    {

        if(v.size()==k && target==0)
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])
            continue;
            if(candidates[i]>target)
            break;
            v.push_back(candidates[i]);
            solve(i+1,v,candidates,target-candidates[i],ans,k);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>>ans;
        vector<int>v;
        vector<int>candidates={1,2,3,4,5,6,7,8,9};

        solve(0,v,candidates,n,ans,k);
        return ans;


    }
};