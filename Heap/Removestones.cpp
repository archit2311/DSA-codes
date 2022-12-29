class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq;
        int sum=0;
        for(int i=0; i<piles.size(); i++)
        {
            sum+=piles[i];
            pq.push(piles[i]);
        }

        for(int j=0; j<k; j++)
        {
            sum=sum-(pq.top()/2);
            int newv=pq.top()-(pq.top()/2);
            pq.pop();
            pq.push(newv);
        }

        return sum;

    }
};
