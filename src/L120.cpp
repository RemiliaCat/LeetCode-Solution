#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        auto m = triangle.size();
        auto &dp = triangle;
        for (int i = 1; i < m; ++i) {
            dp[i][0] += dp[i - 1][0];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] += dp[i - 1][i - 1];
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};
