class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int best = 0;

        for(int p:prices){
            min_so_far = min(min_so_far,p);
            best = max(best,p-min_so_far);
        }

        return best;
        
        
    }
};
