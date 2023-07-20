class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==1)
        return 1;

        int pos=1;
        int res=1;
        int k=1;

        for(int i=1;i<nums.size();i++)
        {
          
            if(nums[i]==nums[i-1] && k<2)
            {
                nums[pos]=nums[i];
                pos++;
                k++;
            }
            if(nums[i]!=nums[i-1])
            {
                k=1;
                nums[pos]=nums[i];
                pos++;
            }
        }

        int ans=pos;
        return ans;
    }
};