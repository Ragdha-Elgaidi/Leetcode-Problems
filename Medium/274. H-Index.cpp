class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1, 0);

        for (int c : citations) {
            if (c >= n) cnt[n]++;   // cap values bigger than n
            else cnt[c]++;
        }

        int have = 0;               // #papers with ≥ current h
        for (int h = n; h >= 0; --h) {
            have += cnt[h];
            if (have >= h) return h;
        }
        return 0;
    }


    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < (int)citations.size(); ++i) {
            if (citations[i] >= i + 1) h = i + 1;
            else break;
        }
        return h;
    }
};
