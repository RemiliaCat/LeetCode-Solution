#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        const short n = s.size();
        auto dp = vector<vector<short>>(n + 1, vector<short>(n + 1));
        for (int i = n - 1; i >= 0; ++i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
        }
        return dp.front().back();
    }
};
