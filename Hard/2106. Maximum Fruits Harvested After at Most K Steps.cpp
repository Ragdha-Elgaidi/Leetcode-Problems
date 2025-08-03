class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0;
        int maxFruits = 0;
        int totalFruitsInWindow = 0;

        for (int right = 0; right < n; right++) {
            totalFruitsInWindow += fruits[right][1];


            int leftPos = fruits[left][0];
            int rightPos = fruits[right][0];

            int disLeftFirst = abs(startPos - leftPos) + (rightPos - leftPos);
            int disRightFirst =
                abs(startPos - rightPos) + (rightPos - leftPos);
            int steps = min(disLeftFirst, disRightFirst);

            while (steps > k && left <= right) {
                totalFruitsInWindow -= fruits[left][1];
                left++;

                if (left <= right) {
                    leftPos = fruits[left][0];
                    disLeftFirst =
                        abs(startPos - leftPos) + (rightPos - leftPos);
                    disRightFirst =
                        abs(startPos - rightPos) + (rightPos - leftPos);
                    steps = min(disLeftFirst, disRightFirst);
                }
            }

            maxFruits = max(maxFruits, totalFruitsInWindow);
        }
        return maxFruits;
    }
};
