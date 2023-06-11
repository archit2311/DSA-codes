class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
       
        int n=nums.size();
  
            for(int j=0;j<n;j++)
            {
                if(s[j]=='R'){
                    nums[j]=nums[j]+d;
                   
                   
                }
                else if(s[j]=='L'){
                    nums[j]=nums[j]-d;
                    
                   
                }
            }

            sort(nums.begin(),nums.end());
            

        
        //distance
        int mod=1000000007;
         long long res=0,sum=0;
        for(long long i=0;i<n;i++){
            res=(res +(i*nums[i]-sum)%mod)%mod;
            sum=(sum+nums[i])%mod;
            
        }
        return res;
    }
};