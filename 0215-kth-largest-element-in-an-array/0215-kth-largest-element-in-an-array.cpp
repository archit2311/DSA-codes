class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size()<k)return nums[0];
        priority_queue<int>pq;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        while(k>0)
        {
            ans=pq.top();
            pq.pop();
            k--;
        }

        return ans;
    }
};