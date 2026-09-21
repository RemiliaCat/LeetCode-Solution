#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        unordered_map<int, int> sum;
        vector<int> values;
        for (auto point : nums) {
            sum[point] += point;
        }
        for (auto [num, points] : sum) {
            values.push_back(num);
        }
        sort(values.begin(), values.end());
        int p = 0, q = 0, prev_num = -1;
        for (int num : values) {
            int cur;
            if (num == prev_num + 1) {
                cur = max(p, q + sum[num]);
            } else {
                cur = p + sum[num];
            }
            q = p;
            p = cur;
            prev_num = num;
        }
        return p;
    }
};
