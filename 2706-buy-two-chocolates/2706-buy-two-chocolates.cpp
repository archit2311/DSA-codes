class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
     
        sort(prices.begin(),prices.end());
        int zz=prices[0]+prices[1];
        if(zz<=money)
            return money-zz;
        else
            return money;
    }
};