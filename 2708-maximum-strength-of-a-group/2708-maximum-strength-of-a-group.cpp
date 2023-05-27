class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        if(nums.size()==1)return nums[0];
        long long ans=1;
        vector<int>pos,neg;
        int countzero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else if(nums[i]>0){
                ans=ans*nums[i];
                 pos.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
                countzero++;
            }
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        
        if(neg.size()%2==0)
        {
            for(int i=0;i<neg.size();i++)
                ans=ans*neg[i];
        }
        else{
            for(int i=0;i<neg.size()-1;i++)
            {
                ans=ans*neg[i];
            }
        }
        
        if(ans==1 && pos.size()>0&& countzero==pos.size())
            return 0;
        else
            return ans;
            
        
    }
};