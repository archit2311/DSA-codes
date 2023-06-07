class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0.0;
        double waitTime=0.0;
        int n=customers.size();
        int finish[n];
        finish[0]=customers[0][0]+customers[0][1];
        for(int i=1;i<n;i++)
        {
            if(finish[i-1]>customers[i][0])
            finish[i]=finish[i-1]+customers[i][1];
            else
            finish[i]=customers[i][0]+customers[i][1];
        }

        for(int i=0;i<n;i++)
        {
            cout<<finish[i]<<" ";
            waitTime+=finish[i]-customers[i][0];
        }

        ans=waitTime/n;
        return ans;


    }
};