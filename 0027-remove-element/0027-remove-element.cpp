class Solution {
public:

    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }

    int removeElement(vector<int>& nums, int val) {
        
        int count=0;
       

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            count++;
        }
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]==val)
            {
                swap(nums[i],nums[j]);
                j--;
            }
            else
            {
                i++;
            }
        }
        return nums.size()-count;

    }
};