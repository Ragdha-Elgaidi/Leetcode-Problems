class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=1;i<(int)prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit +=prices[i]-prices[i-1];
            }
        }
        return profit;
    }


int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), i = 0, profit = 0;

        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            int buy = prices[i]; // vally

            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }

            int sell = prices[i]; // peak

            profit += max(0, sell - buy);
        }

        return profit;
    }
};
