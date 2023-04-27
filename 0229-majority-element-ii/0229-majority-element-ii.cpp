class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int num1,num2;
        int cnt1=0,cnt2=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==num1)
            {
                cnt1++;
            }
            else if(nums[i]==num2)
            cnt2++;

            else if(cnt1==0)
            {
                cnt1=1;
                num1=nums[i];
            }
            else if(cnt2==0)
            {
                cnt2=1;
                num2=nums[i];
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        int cnt11=0,cnt22=0;
        for(int i=0;i<nums.size(); i++)
        {
            if(nums[i]==num1)
            {
                cnt11++;
            }
            else if(nums[i]==num2)
            {
                cnt22++;
            }
        }

        if(cnt11>nums.size()/3)
        ans.push_back(num1);
        if(cnt22>nums.size()/3)
        ans.push_back(num2);

        return ans;
    }
};