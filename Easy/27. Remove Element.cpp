class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};


// another sol

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if(nums[i]==val){
                nums[i]=nums[n-1];
                n--;
            }else{
                i++;
            }
        }
        return n;
    }
};
