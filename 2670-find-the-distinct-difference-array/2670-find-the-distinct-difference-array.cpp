class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>v;
    int n=nums.size();
     int prefix[n];
     int suffix[n];
     set<int>s1;
     set<int>s2;
     prefix[0]=1;
     s1.insert(nums[0]);

     for(int i=1;i<n;i++)
     {
         if(s1.find(nums[i])==s1.end())
         {
             s1.insert(nums[i]);
             prefix[i]=s1.size();
             
             
         }
         else
         prefix[i]=s1.size();
     }

    suffix[n-1]=0;
    s2.insert(nums[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(s2.find(nums[i])==s2.end())
        {
            suffix[i]=s2.size();
            s2.insert(nums[i]);
            
        }
        else{
            suffix[i]=s2.size();
        }
    }

    for(int i=0;i<n;i++)
    {
        v.push_back(prefix[i]-suffix[i]);
    }
     return v;

    }
};