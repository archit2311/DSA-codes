class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        int start=0;
        for(int i=0;i<k-1;i++)
        {
            mp[nums[i]]++;
        }

        for(int i=k-1;i<n;i++)
        {
            mp[nums[i]]++;
            int count=0;
            int res=0;

            for(int j=-50;j<0;j++)
            {
                if(mp[j]>0)
                {
                    count+=mp[j];
                }

                if(count>=x)
                {
                    res=j;
                    break;
                }
            }
            ans.push_back(res);
            mp[nums[start]]--;
            start++;

        }
        return ans;
    }
};