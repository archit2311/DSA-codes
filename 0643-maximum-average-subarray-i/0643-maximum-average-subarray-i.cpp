class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      
        int sum=0;
        for(int i=0;i<k;i++)
        {
           sum+=nums[i]; 
        }
        int ans=sum;
        for(int i=k;i<nums.size();i++)
        {
            sum=sum-nums[i-k]+nums[i];
            ans=max(ans,sum);
        }

        return ((1.0*ans)/k);

    }
};