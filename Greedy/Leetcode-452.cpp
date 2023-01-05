class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();
        int count=0;
    
        sort(points.begin(), points.end(), [] (auto &p1, auto&p2) {
            return p1[1] < p2[1];
        });

        
        int mini=points[0][1];
        
        for(int i=1; i<points.size(); i++)
        {
            
            if(points[i][0]>mini)
            {
                count++;
                mini=points[i][1];
            }
        }
        

        return count+1;
        
    }
    
};
