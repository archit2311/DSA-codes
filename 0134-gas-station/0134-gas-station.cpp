class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int gasCost=0;
        int gasAvai=0;
        int start=0;
        for(int i=0; i<gas.size(); i++)
        {
            gasCost+=cost[i];
            gasAvai+=gas[i];
        }
        if(gasCost>gasAvai)return -1;

        for(int i=0; i<gas.size(); i++)
        {
            total+=gas[i]-cost[i];
            if(total<0)
            {
            start=i+1;
            total=0;
            }

        }
        return start;
    }
};