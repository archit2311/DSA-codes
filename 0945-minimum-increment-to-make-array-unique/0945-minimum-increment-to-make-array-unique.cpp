class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int ans=0;
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                ans+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }

        }
        return ans;






























    //     long long int ans=0;
    //     sort(nums.begin(),nums.end());
    //     vector<int>remain;
    //     int arr[100001]={0};
    //     int n=nums.size();
        
    //     for(int i=0;i<n;i++)
    //     {
            
    //         if(arr[nums[i]]==0)
    //         {
    //             arr[nums[i]]=1;
    //         }
    //         else{
    //             remain.push_back(nums[i]);
    //         }
    //     }

    //     for(int i=0;i<remain.size();i++)
    //     {
    //         for(int j=remain[i]+1;j<100001;j++)
    //         {
    //             if(arr[j]==0)
    //             {
    //                 ans=ans+(j-remain[i]);
    //                 arr[j]=1;
    //                 break;
    //             }
    //         }
    //     }

    //     return ans;
    }
};