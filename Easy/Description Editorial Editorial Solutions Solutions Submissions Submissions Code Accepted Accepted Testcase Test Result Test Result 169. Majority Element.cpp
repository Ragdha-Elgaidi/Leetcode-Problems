class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size();

        for (int num : nums) {
            count[num]++;

            if (count[num] > n / 2) {
                return num;
            }
        }

        return -1;
    }

   int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }

};
