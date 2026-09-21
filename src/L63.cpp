#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    // 这一行遍历完的dp，可以留作给下一行的dp的上一行状态
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
