class Solution {
public:
    
    static bool mycmp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.second==b.second)
            return a.first>b.first;
        else
            return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
     
        vector<int>ans;
        map<int,int>mp;
        vector<pair<int,int>>v;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto x:mp)
        {
            v.push_back({x.first,x.second});
        }
        
        sort(v.begin(),v.end(),mycmp);
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].second;j++)
            {
                ans.push_back(v[i].first);
            }
        }
        
        return ans;
    }
    
};