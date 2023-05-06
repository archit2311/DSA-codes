class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,right=n-1;
        int mod= 1e9+7;
        vector<int>prepower(n,1);

        for(int i=1;i<n;i++)
        {
            prepower[i]=(prepower[i-1]*2)%mod;
        }

        while(left<=right)
        {
            if(nums[left]+nums[right]>target)
            right--;
            else
            {
                ans+=prepower[right-left];
                ans=ans%mod;
                left++;
            }
        }

        

        return ans;

    }
};