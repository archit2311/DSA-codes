class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>ans(nums.size());
        vector<int>conversion(nums.size());
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);

            conversion[i]=nums[i]+maxi;
        }
        ans[0]=conversion[0];
        for(int i=1;i<conversion.size();i++)
        {
            ans[i]=conversion[i]+ans[i-1];
        }

        return ans;
    }
};