class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int>mp;
        int target;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key){
           mp[nums[i+1]]++; 
            }
            
        }

        int maxi=INT_MIN;
        int ans=-1;
        for(auto x:mp)
        {
            if(x.second>maxi)
            {
                maxi=max(maxi,x.second);
                ans=x.first;
            }
        }

        return ans;
    }
};