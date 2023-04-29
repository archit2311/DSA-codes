class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<k;i++)
        {
            ans+=nums[n-1]+i;
        }

        return ans;
        
    }
};