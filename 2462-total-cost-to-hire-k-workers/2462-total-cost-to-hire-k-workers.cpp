class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        long long ans=0;

        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        int i=0,j=costs.size()-1;
        int cnt=0;
        while(cnt<k)
        {
            while(pq1.size()<candidates && i<=j)
            {
                pq1.push(costs[i]);
              i++;
            }
            while(pq2.size()<candidates && j>=i)
            {
                pq2.push(costs[j]);
                j--;
                
            }

            int cost1=pq1.size()>0 ? pq1.top():INT_MAX;
            int cost2=pq2.size()>0 ? pq2.top():INT_MAX;

            if(cost1<=cost2)
            {
                ans+=cost1;
                pq1.pop();
            }
            else
            {
                ans+=cost2;
                pq2.pop();
            }

         cnt++;   
        }
        return ans;
    }
};