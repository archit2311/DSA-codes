class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>ans;
        set<int>l1;
        set<int>l2;
        unordered_set<int>s1;
        unordered_set<int>s2;

        for(int i=0;i<nums2.size();i++)
        {
            s2.insert(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++)
        {
            if(s2.find(nums1[i])==s2.end())
            l1.insert(nums1[i]);
        }

        for(int i=0;i<nums1.size();i++)
        {
            s1.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(s1.find(nums2[i])==s1.end())
            l2.insert(nums2[i]);
        }

        vector<int>v1;
        vector<int>v2;
        for(auto x:l1)
        {
            v1.push_back(x);
        }
         ans.push_back(v1);
        for(auto x:l2)
        {
            v2.push_back(x);
        }

       
        ans.push_back(v2);

        return ans;
    }
};