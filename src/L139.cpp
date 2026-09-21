#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        const int n = s.size();
        auto wordDictSet = unordered_set<string>();
        short maxLen = 0;
        for (auto word : wordDict) {
            if (word.size() > maxLen) {
                maxLen = word.size();
            }
            wordDictSet.insert(word);
        }
        auto dp = vector<bool>(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && i - j <= maxLen &&
                    wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
