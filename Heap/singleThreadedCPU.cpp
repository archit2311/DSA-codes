class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long time=0;
        vector<int>taskOrder;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>>pq;

        vector<array<int, 3>> sortedTasks;
        for(int  i=0;i<tasks.size(); i++)
        {
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());

        int idx=0;
        while (idx < tasks.size() || !pq.empty()) {
            if (pq.empty() && time < sortedTasks[idx][0]) {
                // When the heap is empty, try updating currTime to next
                // task's enqueue time.
                time = sortedTasks[idx][0];
            }
            while(idx<sortedTasks.size() && time>=sortedTasks[idx][0])
            {
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});
                idx++;
            }

            auto [processTime, index] = pq.top();
            pq.pop();

            time+=processTime;
            taskOrder.push_back(index);

        }

        return taskOrder; 
        
    }
};
