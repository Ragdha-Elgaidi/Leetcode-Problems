#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class MagicDictionary {
private:
    // Group words by their length.
    unordered_map<int, vector<string>> buckets;
    
public:
    MagicDictionary() {
    }
    
    // Inserts each word into the bucket corresponding to its length.
    void buildDict(vector<string> dictionary) {
        for (const string &word : dictionary) {
            buckets[word.size()].push_back(word);
        }
    }
    
    // Returns true if there is any word in the dictionary that differs by exactly one character.
    bool search(string searchWord) {
        int n = searchWord.size();

        if (buckets.find(n) == buckets.end()) {
            return false;
        }
        
        // Check all candidate words of the same length.
        for (const string &candidate : buckets[n]) {
            int mismatch = 0;
            for (int i = 0; i < n; ++i) {
                if (searchWord[i] != candidate[i]) {
                    mismatch++;
                    if (mismatch > 1) {
                        break;
                    }
                }
            }
            if (mismatch == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
