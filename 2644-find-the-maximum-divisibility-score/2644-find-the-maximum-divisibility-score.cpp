class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int fans=0;
        int ans=0;
        for(int i=0; i<divisors.size();i++)
        {
            int curr=0;
            for(int j=0;j<nums.size(); j++)
            {
                if((nums[j]%divisors[i])==0)
                {
                    curr++;
                }
            }
            if(curr>ans){
                ans=curr;
                fans=i;
            }
            if(curr==ans)
            {
                if(divisors[i]<divisors[fans])
                {
                    fans=i;
                }
            }
            
        }
        return divisors[fans];
    }
};