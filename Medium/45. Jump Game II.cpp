class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();

        if (n <= 1) {
            return 0;
        }

        int jumps = 0;
        int currEnd = 0;
        int currFar = 0;

        for (int i = 0; i < n - 1; i++) {
            currFar = max(currFar, i + nums[i]);
            if (i == currEnd) {
                jumps++;
                currEnd = currFar;
            }

            if (currEnd >= n - 1) {
                break;
            }
        }
        return jumps;
    }
};
