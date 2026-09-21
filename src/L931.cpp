#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        auto n = matrix.size();
        auto &dp = matrix;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int mn = dp[i + 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i + 1][j - 1]);
                }
                if (j + 1 < n) {
                    mn = min(mn, dp[i + 1][j + 1]);
                }
                dp[i][j] += mn;
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
