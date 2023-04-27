class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int>mp;
        int ans=-1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                mp[nums[i]]++;
            }
        }
        
        for(auto x:mp)
        {
            if(x.second>maxi)
            {
                maxi=x.second;
                ans=x.first;
            }
        }
        return ans;
        
    }
};