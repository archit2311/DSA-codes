class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>avg(n,-1);
        long long int prefixSum[n];
        prefixSum[0]=0;
        for(int i=1;i<n;i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        for(int i=k;i<n-k;i++)
        {
            avg[i]=(prefixSum[i+k]+nums[i+k]-prefixSum[i-k])/(2*k+1);

        }
        return avg;

    }
};