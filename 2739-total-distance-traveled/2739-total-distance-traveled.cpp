class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dist=0;
        
        while(mainTank>=5)
        {
            dist+=5;
            mainTank=mainTank-5;
            if(additionalTank>0){
            mainTank++;
            additionalTank--;
            }
        }

        dist+=mainTank;

        return dist*10;
    }
};