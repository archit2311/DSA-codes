class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i;
        int countZero=0;
        int len=0,firstZero;
        if(nums[0]==0)
        i=1;
        else
        i=0;

        for(;i<n;i++)
        {
            if(nums[i]==0 && countZero==0)
            {
                firstZero=i;
                countZero++;
            }
            else if(nums[i]==1){
            len++;
            }
            else
            {
                ans=max(ans,len);
                countZero=0;
                len=0;
                i=firstZero;
            }
        }
        if(len==n)
        ans=n-1;
        else
        ans=max(ans,len);
        return ans;
    }
};