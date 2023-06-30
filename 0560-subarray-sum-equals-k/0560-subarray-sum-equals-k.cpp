class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int preSum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<arr.size();i++)
        {
            preSum+=arr[i];
            if(mp.find(preSum-k)!=mp.end())
            ans+=mp[preSum-k];
            mp[preSum]++;
        }
        return ans;
    }
};