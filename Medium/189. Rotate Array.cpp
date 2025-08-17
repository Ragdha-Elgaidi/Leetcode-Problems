class Solution {
public:
    inline void norm(int& k, int n) {
        if (n)
            k %= n;
    }

   void reverseRange(vector<int>& a, int l, int r) {
        while (l < r) {
            swap(a[l++], a[r--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0)
            return;

        norm(k, n);

        while (k--) {
            int last = nums.back();

            for (int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }

            nums[0] = last;
        }
    }
void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k == 0) {
            return;
        }

        norm(k, n);

        vector<int> out(n);

        for (int i = 0; i < n; i++) {
            out[(i + k) % n] = nums[i];
        }

        nums.swap(out);
    }

void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k == 0) {
            return;
        }

        norm(k, n);

        reverseRange(nums, 0, n - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
    }


};
