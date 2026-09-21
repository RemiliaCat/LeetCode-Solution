#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        vector<int> &dp = nums;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return dp[0];
        }
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
