class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int min_buy=prices[0];
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-min_buy);
            min_buy=min(min_buy,prices[i]);
            
        }
        return profit;
    }
};